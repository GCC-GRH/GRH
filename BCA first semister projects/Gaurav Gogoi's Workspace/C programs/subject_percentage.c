#include<stdio.h>
int main(){
    int english, chemistry, maths, biology, alt, physics, percentage, fourth, marks;
    printf("This program is used for calculating the percentage of your AHSEC result"); //Source code by Gaurav Gogoi
    printf("\n Total marks obtained in English : ");
    scanf("%d",&english);
    printf("\n Total marks obtained in Chemistry (IF fourth, enter 0) : ");
    scanf("%d",&chemistry);
    printf("\n Total marks obtained in Maths : ");
    scanf("%d",&maths);
    printf("\n Total marks obtained in Biology/Computer Science : ");
    scanf("%d",&biology);
    printf("\n Total marks obtained in Alternative English/Assamese/Physical Education : ");
    scanf("%d",&alt);
    printf("\n Total marks obtained in Physics : ");
    scanf("%d",&physics);
    printf("\n Evaluating & Estimating your marksheet record, won't take long!");
    marks=english+chemistry+maths+biology+alt+physics;
    percentage=marks/5;
    printf("\n Your percentage is %d and you obtained a total marks of %d",percentage,marks);
if(english<chemistry){
   if(english<maths){
    if(english<biology){
        if(english<alt){
            if(english<physics){
                printf("\n English is your fourth subject");
            }
        }
    }
   }
}else{
    if(chemistry<english){
   if(chemistry<maths){
    if(chemistry<biology){
        if(chemistry<alt){
            if(chemistry<physics){
                printf("\n Chemistry is your fourth subject");
            }
        }
    }
   }
}else{
    if(maths<chemistry){
   if(maths<english){
    if(maths<biology){
        if(maths<alt){
            if(maths<physics){
                printf("\n Mathematics is your fourth subject");
            }
        }
    }
   }
}else{
    if(biology<chemistry){
   if(biology<maths){
    if(biology<english){
        if(biology<alt){
            if(biology<physics){
                printf("\n Biology/Computer science is your fourth subject");
            }
        }
    }
   }
}else{
    if(alt<chemistry){
   if(alt<maths){
    if(alt<biology){
        if(alt<english){
            if(alt<physics){
                printf("\n Alternative english/Assamese/Physical education is your fourth subject");
            }
        }
    }
   }
}else{
    if(physics<chemistry){
   if(physics<maths){
    if(physics<biology){
        if(physics<alt){
            if(physics<physics){
                printf("\n Physics is your fourth subject");
            }
        }
    }
   }
}
}
}
}
}
}

 return 0; 
}
