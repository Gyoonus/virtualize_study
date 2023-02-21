#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>


enum ops {Locals = 116, Plus  = 135, Load   = 60, Goto = 231,
    Const  = 3,   Store = 122, Return = 72};

unsigned char bytecode[42]  = {
    Locals,10,00,0,0,Const,1,0,0,0,Locals,24,0,0,0,Load,Plus,Return,Store,Locals,
    28,0,0,0,Const,0,0,0,0,Store,Goto,4,0,0,0,Locals,10,0,0,0,Load,Return};

struct _sp{

    int _int;
    int * _vs;
};

int virt() {

    unsigned char* pc = bytecode;
    struct _sp* sp = (struct _sp*) malloc(sizeof(_sp) *10);
    int vars = 0;

    while (1) {
        switch (*pc) {
            case Const: pc++; 
                        (sp+1)->_int = *((int *)pc); 
                        sp++; pc+=4; 
                        break;
            case Load: pc++;
                       sp->_int = *((int *)sp->_vs); 
                       break;
            case Goto: pc++; 
                       pc+= *((int *)pc); 
                       break;
            case Plus: pc++; 
                       (sp+-1)->_int=sp->_int+(sp+-1)->_int; 
                       sp--; 
                       break;
            case Return: pc++; 
                         return (sp->_int); 
                         break;
            case Store: pc++; 
                        *((int *)(sp+-1)->_vs)=sp->_int; 
                        sp+=-2; 
                        break;
            case Locals: pc++; 
                         (sp+1)->_vs=(void *)(pc); 
                         sp++; 
                         pc+=4; 
                         break;
        }
    }


}
int main()
{

    printf("%d\n", virt());
    return 0;
}
