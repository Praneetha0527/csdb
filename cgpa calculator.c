#include<stdio.h>
int main()
{
    int i,n;
    float gs,cs,grade,credit;
    printf("Enter the no. of subjects:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the grade and credit hours for subject%d:",i+1);
        scanf("%f %f",&grade,&credit);
        gs+=grade*credit;
        cs+=credit;
    }
    float cgpa=gs/cs;
    printf("CGPA:%.2f\n",cgpa);
    return 0;
}
