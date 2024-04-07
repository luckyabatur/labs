#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "symbol.h"
// #include "stack.h" //�� ����� �� �������� ������ ������ � �������� ����� header
#include "stack.c"
#include "tree.h"

int op_priority(char op) {
    switch(op) {
        case OP_MINUS:
        case OP_PLUS:
            return 1;
        case OP_MULT:
        case OP_DIVIDE:
            return 2;
        case OP_POW:
            return 3;
        case OP_UNARY_MINUS:
            return 4;
    }
    return -1;
}

/*int tn_priority(TN* tn) {
    switch(tn->t.type) {
        case symb_NUMBER:
        case symb_VAR:
            return 100;
        case symb_OP:
            return op_priority(tn->t.data.op);
        default:
            return -1; // �� ������ ���� ������ � ������
    }
}*/

OP_ASSOC op_assoc(OP op) {
    switch(op) {
        case OP_MINUS:
        case OP_PLUS:
        case OP_MULT:
        case OP_DIVIDE:
            return ASSOC_LEFT;
        case OP_UNARY_MINUS:
        case OP_POW:
            return ASSOC_RIGHT;
    }
    return -1;
}

char op_to_char(OP op) {
    switch(op) {
        case OP_MINUS:
        case OP_PLUS:
        case OP_MULT:
        case OP_DIVIDE:
        case OP_POW:
            return op;
        case OP_UNARY_MINUS:
            return '-';
    }
    return -1;
}

bool is_space(int c) {
    return (c == ' ') || (c == '\n') || (c == '\t');
}

// ���������� ������� � ������ ��������� �������� ������
int next_char() {
    int c;
    while(is_space(c = getchar())) {} // ������ ����: �� ������ - ����� � �������
    return c;
}

bool next_symbol(symbol *out) {
    // ����� ����� ������� ��� ���������� ���������� ������
    // ���� ��� �����, �����, ������������ � ������� ������� �� ������� ��� � ��������
    static symb_TYPE prev_type = symb_NONE;

    int c = next_char();
    if(c == EOF) {
        out->type = symb_NONE; // �� ������ ������
        prev_type = symb_NONE; // ���� �� ������
        return false; // ��, �� �������
    } else if(c == '.' || (c >= '0' && c <= '9')) {
        // ����� ����� ���������� � �����: .9 == 0.9
        ungetc(c, stdin);
        out->type = symb_NUMBER;
        scanf("%f", &(out->data.number)); // ������ � ���������
    } else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        ungetc(c, stdin);
        out->type = symb_VAR;
        //scanf("%[^\n\t+-*/^()]", out->data.var);
		scanf("%[a-zA-Z]", out->data.var);//������ ���, ��� � ���������� ����� �������� ������ �����
    } else if(c == '(') {
        out->type = symb_LEFT_BR;
    } else if(c == ')') {
        out->type = symb_RIGHT_BR;
    } else if(c == '+' || c == '*' || c == '/' || c == '^') {
        out->type = symb_OP;
        out->data.op = c;
    } else if(c == '-') {
        out->type = symb_OP;
        // ��� ���� ���������, ������� �� � ��� �����
        if(prev_type == symb_OP || prev_type == symb_NONE || prev_type == symb_LEFT_BR) {
            out->data.op = OP_UNARY_MINUS;
        } else {
            out->data.op = OP_MINUS;
        }
    } else {
        // ����� ������: �� ������ ���� �������, ������� �� �� ����� �� ���������
        out->type = symb_NONE;
        out->data.c = c;
    }
    
    // ���������� � ����������� ���������� ��� ������ ��� ���������� ������
    prev_type = out->type;
    
    return true;
}

bool build_tree(TN **tree, STACK *rev) {
    if(stack_empty(rev)) {
        return false;
    }
    symbol t = stack_pop(rev);
    (*tree) = (TN*)malloc(sizeof(TN));
    (*tree)->t = t;

    bool res = true;
    if(t.type == symb_OP) {
        if(t.data.op == OP_UNARY_MINUS) {
            (*tree)->l = NULL;
            res = res && build_tree(&((*tree)->r), rev);
        } else {
            res = res && build_tree(&((*tree)->r), rev);
            // ���� res ��� false, �� build_tree ��� �� ���������
            res = res && build_tree(&((*tree)->l), rev);
        }
    }
    return res;
}

void print_tree(TN *tree, int lev) {
	

	if(tree->t.type == symb_OP)
	{
		print_tree(tree->r, lev+1);
	}
    for(int i = 0; i < lev; i++) {
        printf("\t");
    }
    switch(tree->t.type) {
        case symb_NUMBER:
            printf("%.2lf\n", tree->t.data.number);
            break;
        case symb_VAR:
            printf("%s\n", tree->t.data.var);
            break;
        case symb_OP:
            if(tree->t.data.op == OP_UNARY_MINUS) {
                printf("-\n");
                // print_tree(tree->r, lev+1);
            } else {
                printf("%c\n", op_to_char(tree->t.data.op));
//                print_tree(tree->l, lev+1);
//                print_tree(tree->r, lev+1);
            }
            break;
        default:
            fprintf(stderr, "This symlbol must not be in the tree already");
            return;
    }
    if(tree->t.type == symb_OP && tree->t.data.op != OP_UNARY_MINUS)
	{
		print_tree(tree->l, lev+1);
	}

}

void print_expr(TN *tree) {
    switch(tree->t.type) {
        case symb_NUMBER:
            printf("%.2lf", tree->t.data.number);
            break;
        case symb_VAR:
            printf("%s", tree->t.data.var);
            break;
        case symb_OP:
            if(tree->t.data.op == OP_UNARY_MINUS) {
                printf("-");
                if (tree->r->t.type == symb_OP)
                {
                    printf("(");
                    print_expr(tree->r);
                    printf(")");
                }
                else
                    print_expr(tree->r);
            } else {
                if(tree->l->t.type == symb_OP && op_priority(tree->t.data.op) > op_priority(tree->l->t.data.op) || tree->l->t.data.op == OP_UNARY_MINUS)
                {
                	printf("(");
                	print_expr(tree->l);
                	printf(")");
				}
				else
				{
					print_expr(tree->l);
				}
//				printf("(");
//				print_expr(tree->l);//�������� ����������� ������ ������, �������� (2+3) -> 2+3
                printf("%c", op_to_char(tree->t.data.op));
//                print_expr(tree->r);//�������� ����������� ������ ������, �������� (2+3) -> 2+3
//                printf(")");
				if(tree->r->t.type == symb_OP && op_priority(tree->t.data.op) > op_priority(tree->r->t.data.op) || tree->r->t.data.op == OP_UNARY_MINUS)
                {
                	printf("(");
                	print_expr(tree->r);
                	printf(")");
				}
				else
				{
					print_expr(tree->r);
				}
            }
            break;
        default:
            fprintf(stderr, "This symlbol must not be in the tree already");
            return;
    }
}

void laba(TN* tree)
{   
    if (tree == NULL)
        return;
    if (tree->t.type != symb_OP || tree->t.data.op != OP_PLUS)
    {
        laba(tree->l);
        laba(tree->r);
    }
    else if (tree->l->t.type == symb_NUMBER && tree->l->t.data.number == 0)
        {
            free(tree->l);
            TN* help = tree->r;
            *tree = *tree->r;
            free(help);
            laba(tree);
        }
    else if (tree->r->t.type == symb_NUMBER && tree->r->t.data.number == 0)
        {
            free(tree->r);
            TN* help = tree->l;
            *tree = *tree->l;
            free(help);
            laba(tree);
        }
    laba(tree->l);
    laba(tree->r);
}



int main() {
	STACK *s, *rev;
    symbol t;
    
    s = stack_create();
    rev = stack_create();
    
    while(next_symbol(&t)) {
        switch(t.type) {
            case symb_NONE:
                fprintf(stderr, "Error: symbol %c not recognized\n", t.data.c);
                return 1;
                
            case symb_OP:
                for(;;) {
                    if(stack_empty(s)) break;
                    symbol top = stack_peek(s);
                    if(top.type != symb_OP) break;
                    
                    if((op_assoc(t.data.op) == ASSOC_LEFT && op_priority(t.data.op) <= op_priority(top.data.op))
                    || (op_assoc(t.data.op) == ASSOC_RIGHT && op_priority(t.data.op) < op_priority(top.data.op))
                    ) {
                        // �������������
                        stack_pop(s);
                        stack_push(rev, top);
                    } else {
                        break;
                    }
                }
            
                // ����� ����� �������� �� �������� �����
                stack_push(s, t);
                break;
                
            case symb_NUMBER:
            case symb_VAR:
                // ��� ���� ����� ������ � �������� ����
                stack_push(rev, t);
                break;

            case symb_LEFT_BR:
                stack_push(s, t);
                break;
                
            case symb_RIGHT_BR:
                for(;;) {
                    if(stack_empty(s)) {
                        fprintf(stderr, "Error: closing bracket hasn't pair");
                        return 2;
                    }
                    symbol top = stack_peek(s);
                    if(top.type == symb_LEFT_BR) {
                        stack_pop(s);
                        break;
                    } else {
                        // �������������
                        stack_pop(s);
                        stack_push(rev, top);
                    }
                }
                break;
        }
    }
    
    while(!stack_empty(s)) {
        t = stack_pop(s);
        if(t.type == symb_LEFT_BR) {
            fprintf(stderr, "Error: opening bracket hasn't pair");
            return 2;
        }
        stack_push(rev, t);
    }
    
    // Build tree
    if(stack_empty(rev)) {
        fprintf(stderr, "Error: expression is empty");
        return 3;
    }

    TN *root = NULL;
    if(!build_tree(&root, rev)) {
        fprintf(stderr, "Error while building tree: don't find one of operands");
        return 4;
    }
    if(!stack_empty(rev)) {
        fprintf(stderr, "Error while building tree: extra operands or opetators");
        return 4;
    }

    // print_tree(root, 0);

    laba(root);

	// print_tree(root, 0);

    print_expr(root);
    printf("\n");
}

