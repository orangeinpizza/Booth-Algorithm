//Program On Booth Algorithm

#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

#include<ctype.h>

#include<string.h>

 

void _2comp(int negm[],int a[],int n)

{

    int c=1;

    int i;

   

    for(i=0;i<n;i++)

    {

        if(a[i]==0)

        {

            negm[i]=1;

        }

        else

        {

            negm[i]=0;

        }

    }

   

    for(i=0;i<n;i++)

    {

        if(c==1)

        {

            if(negm[i]==1)

            {

                negm[i]=0;

                c=1;

            }

           

            else

            {

                negm[i]=1;

                c=0; 

            }

        }

    }

}

/////

void sum(int a[],int b[],int n)

{

    int i,c=0;

   

    for(i=0;i<n;i++)

    {

        if(c==1)

        {

            if(a[i]==1 && b[i]==1)

            {

                a[i]=1;

                c=1;

            }

           

            else if(a[i]==0 && b[i]==0)

            {

                a[i]=1;

                c=0;

            }

           

            else if((a[i]==1 && b[i]==0) || (a[i]==0 && b[i]==1))

            {

                a[i]=0;

                c=1;

            }

        }

       

        else

        {

            if(a[i]==1 && b[i]==1)

            {

                a[i]=0;

                c=1;

            }

           

            else if(a[i]==0 && b[i]==0)

            {

                a[i]=0;

                c=0;

            }

           

            else if((a[i]==1 && b[i]==0) || (a[i]==0 && b[i]==1))

            {

                a[i]=1;

            }

        }

    }

}

/////

void shift(int a[],int q[],int n,int *q0)

{

    int i=0;

   

    *q0=q[0];

    q[0]=q[1];

    while(i<=n-2)

    {

        q[i]=q[i+1];

        i++;

    }

   

    q[n-1]=a[0];

   

    i=0;

    while(i<=n-2)

    {

        a[i]=a[i+1];

        i++;

    }

}

/////

int result(int a[],int q[],int n)

{

    int ans=0;

    int i=0,j,r;

    int h;

   

    while(i<n)

    {

        h=1;

        for(j=1;j<=i;j++)

        {

            h=h*2;

        }

        r=j;

        ans+=q[i]*h;

        i++;

    }

    i=0;

    while(i<n)

    {

        h=1;

        for(j=1;j<=r;j++)

        {

            h=h*2;

        }

        r++;

       

        ans+=a[i]*h;

        i++;

    }

   

    return ans;

}

/////

void comp(int a[],int q[],int n)

{

    int i,c=1;

   

    for(i=0;i<n;i++)

    {

        if(a[i]==0)

        {

            a[i]=1;

        }

        else

        {

            a[i]=0;

        }

    }

   

    for(i=0;i<n;i++)

    {

        if(q[i]==0)

        {

            q[i]=1;

        }

        else

        {

            q[i]=0;

        }

    }

   

    for(i=0;i<n;i++)

    {

        if(q[i]==1 && c==1)

        {

            q[i]=0;

            c=1;

        }

       

        else if(q[i]==0 && c==1)

        {

            q[i]=1;

            c=0;

        }

    }

   

    for(i=0;i<n;i++)

    {

        if(a[i]==1 && c==1)

        {

            a[i]=0;

            c=1;

        }

       

        else if(a[i]==0 && c==1)

        {

            a[i]=1;

            c=0;

        }

    }

   

}

/////

void two_comp_single(int p[],int n)

{

    int c=1;

    int i;

   

    for(i=0;i<n;i++)

    {

        if(p[i]==0)

        {

            p[i]=1;

        }

        else

        {

            p[i]=0;

        }

    }

   

    for(i=0;i<n;i++)

    {

        if(c==1)

        {

            if(p[i]==1)

            {

                p[i]=0;

                c=1;

            }

           

            else

            {

                p[i]=1;

                c=0; 

            }

        }

    }

}

/////

void dec2bin(int x,int y,int m[],int q[],int *n,int a[])

{

    int i,k=0,f1=0,f2=0;

   

    if(x<0)

    {

        x=abs(x);

        f1=1;

    }

   

    if(y<0)

    {

        y=abs(y);

        f2=1;

    }

   

    while(x!=0 || y!=0)

    {

        if(k>3)

        {

            *n=*n+1;

        }

        m[k]=x%2;

        q[k]=y%2;

        x=x/2;

        y=y/2;

        k++;

    }

   

    *n=*n+1;

    q[*n-1]=0;

    m[*n-1]=0;

   

   

    for(i=0;i<*n;i++)

    {

        a[i]=0;

    }

   

    if(f1==1)

    {

        two_comp_single(m,*n);

    }

   

    if(f2==1)

    {

        two_comp_single(q,*n);

    }

}

/////

int main()

{

    int x,y,q0=0;

    int ans;

    int i,n=4;

    int m[n],q[n],a[n];

    printf("\nBOOTH ALGORITHM : ");

   

    for(i=0;i<n;i++)

    {

        q[i]=0;

        m[i]=0;

    }

   

    printf("\nEnter the two numbers to multiply : ");

    scanf("%d %d",&x,&y);

   

    dec2bin(x,y,m,q,&n,a);

   

    printf("\nBinary Form Of 'x' ie %d : M -> ",x);

    for(i=n-1;i>=0;i--)   

        printf("%d",m[i]);

 

    printf("\nBinary Form Of 'y' ie %d : Q -> ",y);

 

    for(i=n-1;i>=0;i--)   

        printf("%d",q[i]);

    printf("\n");

   

    int negm[n];

    int j=n,k=1;

   

    _2comp(negm,m,n);

    printf("Neg M ie (-M) -> ");

    for(i=n-1;i>=0;i--)
        printf("%d",negm[i]);
    printf("\n");
    printf("\n\t\t\t----ITERATIONS----\n");

   

    while(j--)

    {
        
        printf("\n\t\t\tq1 = %d && q0 = %d",q[0],q0);

        if(q[0]==1 && q0==0)

        {

            sum(a,negm,n);

        }

       

        else if(q[0]==0 && q0==1)

        {

            sum(a,m,n);

        }

        shift(a,q,n,&q0);
        printf("\nArray 'a': ");
        for(i=0;i<n;i++)
            printf("%d",a[i]);
        printf("\tArray 'q': ");
        for(i=0;i<n;i++)
            printf("%d",q[i]);    
        printf("\tArray 'm': ");
        for(i=0;i<n;i++)
            printf("%d",m[i]);  
        printf("\n");
    }

   

    if(a[n-1]==1)

    {

        comp(a,q,n);

        k=-1;

    }

    ans=result(a,q,n);

    ans*=k;

    printf("\n\nMultiplication Of %d & %d is : %d",x,y,ans);

   

return 0;

}
/*


********************
BOOTH ALGORITHM : 
Enter the two numbers to multiply : 
Binary Form Of 'x' ie 2 : M -> 00000010
Binary Form Of 'y' ie -78 : Q -> 10110010
Neg M ie (-M) -> 11111110

			----ITERATIONS----

			q1 = 0 && q0 = 0
Array 'a': 00000000	Array 'q': 10011010	Array 'm': 01000000

			q1 = 1 && q0 = 0
Array 'a': 11111111	Array 'q': 00110100	Array 'm': 01000000

			q1 = 0 && q0 = 1
Array 'a': 00000000	Array 'q': 01101001	Array 'm': 01000000

			q1 = 0 && q0 = 0
Array 'a': 00000000	Array 'q': 11010010	Array 'm': 01000000

			q1 = 1 && q0 = 0
Array 'a': 11111111	Array 'q': 10100100	Array 'm': 01000000

			q1 = 1 && q0 = 1
Array 'a': 11111111	Array 'q': 01001001	Array 'm': 01000000

			q1 = 0 && q0 = 1
Array 'a': 00000000	Array 'q': 10010011	Array 'm': 01000000

			q1 = 1 && q0 = 0
Array 'a': 11111111	Array 'q': 00100110	Array 'm': 01000000


Multiplication Of 2 & -78 is : -156











********************
BOOTH ALGORITHM : 
Enter the two numbers to multiply : 
Binary Form Of 'x' ie -45 : M -> 1010011
Binary Form Of 'y' ie -7 : Q -> 1111001
Neg M ie (-M) -> 0101101

			----ITERATIONS----

			q1 = 1 && q0 = 0
Array 'a': 0110100	Array 'q': 0011111	Array 'm': 1100101

			q1 = 0 && q0 = 1
Array 'a': 0010111	Array 'q': 0111111	Array 'm': 1100101

			q1 = 0 && q0 = 0
Array 'a': 0101111	Array 'q': 1111110	Array 'm': 1100101

			q1 = 1 && q0 = 0
Array 'a': 1100100	Array 'q': 1111101	Array 'm': 1100101

			q1 = 1 && q0 = 1
Array 'a': 1001000	Array 'q': 1111011	Array 'm': 1100101

			q1 = 1 && q0 = 1
Array 'a': 0010000	Array 'q': 1110111	Array 'm': 1100101

			q1 = 1 && q0 = 1
Array 'a': 0100000	Array 'q': 1101110	Array 'm': 1100101


Multiplication Of -45 & -7 is : 315

********************

BOOTH ALGORITHM : 
Enter the two numbers to multiply : 
Binary Form Of 'x' ie -45 : M -> 1010011
Binary Form Of 'y' ie 54 : Q -> 0110110
Neg M ie (-M) -> 0101101

			----ITERATIONS----

			q1 = 0 && q0 = 0
Array 'a': 0000000	Array 'q': 1101100	Array 'm': 1100101

			q1 = 1 && q0 = 0
Array 'a': 0110100	Array 'q': 1011001	Array 'm': 1100101

			q1 = 1 && q0 = 1
Array 'a': 1101000	Array 'q': 0110010	Array 'm': 1100101

			q1 = 0 && q0 = 1
Array 'a': 1111011	Array 'q': 1100100	Array 'm': 1100101

			q1 = 1 && q0 = 0
Array 'a': 0111000	Array 'q': 1001000	Array 'm': 1100101

			q1 = 1 && q0 = 1
Array 'a': 1110000	Array 'q': 0010000	Array 'm': 1100101

			q1 = 0 && q0 = 1
Array 'a': 1011011	Array 'q': 0100000	Array 'm': 1100101


Multiplication Of -45 & 54 is : -2430

********************
BOOTH ALGORITHM : 
Enter the two numbers to multiply : 
Binary Form Of 'x' ie 89 : M -> 01011001
Binary Form Of 'y' ie 96 : Q -> 01100000
Neg M ie (-M) -> 10100111

			----ITERATIONS----

			q1 = 0 && q0 = 0
Array 'a': 00000000	Array 'q': 00001100	Array 'm': 10011010

			q1 = 0 && q0 = 0
Array 'a': 00000000	Array 'q': 00011000	Array 'm': 10011010

			q1 = 0 && q0 = 0
Array 'a': 00000000	Array 'q': 00110000	Array 'm': 10011010

			q1 = 0 && q0 = 0
Array 'a': 00000000	Array 'q': 01100000	Array 'm': 10011010

			q1 = 0 && q0 = 0
Array 'a': 00000000	Array 'q': 11000000	Array 'm': 10011010

			q1 = 1 && q0 = 0
Array 'a': 11001011	Array 'q': 10000001	Array 'm': 10011010

			q1 = 1 && q0 = 1
Array 'a': 10010111	Array 'q': 00000011	Array 'm': 10011010

			q1 = 0 && q0 = 1
Array 'a': 10000100	Array 'q': 00000110	Array 'm': 10011010


Multiplication Of 89 & 96 is : 8544

********************

*/
