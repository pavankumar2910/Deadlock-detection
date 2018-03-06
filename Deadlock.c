
#include<stdio.h>
#include<string.h>
void expident(int [10][10],int,int);


void main()
{
int mat[10][10],n1[10];
int a=0,b=0,c=0,d=0,i=0,j=0,k=0,q=0,n=0,r=0,w=0,x=0,y=0,q1=0;
int getrow(int [10][10],int,int);
void nonexpident(int [10][10],int [10],int,int);


printf("enter number of processes\t");
scanf("%d",&a);
printf("\nenter number of resources\t");
scanf("%d",&b);
for(i=0;i<b;i++)
{
printf("\nenter the instance of resource R%d\t",i+1);
scanf("%d",&n1[i]);
}
n=a+b;
printf("\nEnter the Adjacency matrix of the resource graph\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&mat[i][j]);
}
}
printf("\nmatrix entered is\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %d",mat[i][j]);
}
printf("\n");
}

for(i=a;i<n;i++)
{
for(j=0;j<n;j++)
{
x+=mat[i][j];
}
}
for(i=0;i<b;i++)
{
y+=n1[i];
}

if(x==y)         //checking for expidency
{
printf("\n The Graph is expident\n");
expident(mat,a,b);

}
else
{
printf("\n The Graph is not expident\n");
nonexpident(mat,n1,a,b);

}

}






void nonexpident(int m[10][10],int r[10],int g,int h)
{

int i=0,j=0,a[6],p1=0,k=0,k1=0,x[10],x1[10],n=0;

n=g+h;
for(j=0;j<10;j++)
{
x[j]=0;

}

printf("\n Converting the graph into expident graph\n");
for(i=g;i<n;i++)
{
for(j=0;j<n;j++)
{
x[k1]+=m[i][j];

}
k1++;
}

for(i=0;i<k1;i++)
{
x1[i]=r[i]-x[i];

}

for(i=0;i<k1;i++)
{
if(x1[i]>=1)
{
k=i+g;
p1=getrow(m,k,n);

m[p1][k]=0;                             //converting the non expident graph to expident graph
m[k][p1]=1;

break;
break;
}
}
expident(m,g,h);                       //calling the function to perform graph reduction

}





void expident(int mat[10][10],int a,int b)
{
int c=0,d=0,i=0,n=0,j=0,k=0,q=0,r=0,z=100,w=0,x=0,y=0,q1=0,zz=0;
int B[10][10],dr=0,dc=0,o[10];

n=a+b;

for(i=0;i<n;i++)
{
o[i]=1;
}
x=n;
r=n-1;

for(d=0;d<r;d++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{

w+=mat[i][j];                // finding the sink

}
if(w==0)
{
z=i;
break;
break;
}
w=0;
}

if(z!=100)                  
{
for(i=0;i<n;i++)
{
if(mat[i][z]==1)
{
mat[i][z]=0;
q=i;

q1=getrow(mat,i,n);    // deleting the request edges of the sink
mat[q1][q]=0;
mat[q][q1]=1;          // granting other process request

}
}
o[z]=0;
dr=z;
dc=z;
for (i = 0; i < n; i++)
 if (i != dr)
 {
 for (j = 0; j <n; j++)
 if (j != dc)
 {
 if (i < dr && j < dc)
 B[i][j] = mat[i][j];
 else if (i < dr && j > dc)
 B[i][j-1] = mat[i][j];
 else if (i > dr && j < dc)
 B[i-1][j]=mat[i][j];
  else
 B[i-1][j-1]=mat[i][j];
 }

}
n=n-1;

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
mat[i][j]=B[i][j];
}
}
}

else                        
{

printf("\nDeadlock !!!!\n");
printf("\nDeadlock is in between : ");
zz=1;
for(i=0;i<a;i++)
{
if(o[i]==1)                      // printing the processes involed in deadlock
printf(" P%d",i+1);
}
for(i=a;i<n;i++)
{
if(o[i]==1)
printf(" R%d",i-a+1);           //printing the resources involed in deadlock
}

break;
break;


}
z=100;
}
if(zz==0)
{
printf("\n No Deadlock");

}
printf("\n\n\n\n");
}

int getrow(int m[10][10],int k,int n)   //algorithm to find the process to which we need to allocate the resource
{
int i,j,a[10],p=0;
for(j=0;j<10;j++)
{
a[j]=0;
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i]+=m[i][j];
}
}

for(i=0;i<n;i++)
{
if(m[i][k]==1)
{
if(a[i]==1)
{
p=i;
break;
break;
break;
}
}
}
return p;
}


