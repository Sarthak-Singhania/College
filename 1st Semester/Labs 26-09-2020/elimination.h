#define N 20

int eliminate(float a[][N],int n)
{
    int exchange=0;
    for(int row=0;row<n-1;row++)
    {
        for(int i=row+1;i<n;i++)
        {
            if(a[row][row]==0.0)
            {
                int k;
                for(k=row+1;k<n;k++) 
                    if(a[k][row]!=0) break;
                float temp;
                exchange++;
                for(int col=row;col<=n;col++)
                {
                    temp=a[row][col];
                    a[row][col]=a[k][col];
                    a[k][col]=temp;
                } 
            }
            float c=-a[i][row]/a[row][row];
            a[i][row]=0.0;
            for(int j=row+1;j<n;j++)
                a[i][j]+=c*a[row][j];
        }
    }
    return exchange;
}
float determinant(float a[][N],int n)
{
    float d,b[N][N];
    if(n==1) return a[0][0];
    else if(n==2) return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<0;j++) b[i][j]=a[i][j];
        }
        d=((eliminate(b,n)%2)==0)?1:-1;
        for(int i=0;i<n;i++) d*=b[i][i];
        return d;
    }
    
}

float cofactor(float a[][N],int n,int i,int j)
{
    float prime[N][N];
    for(int r=0;r<i;r++)
    {
        for(int c=0;c<j;c++) prime[r][c]=a[r][c];
        for(int c=j+1;c<n;c++) prime[r][c-1]=a[r][c];
    }
    for(int r=i+1;r<n;r++)
    {
        for(int c=0;c<j;c++) prime[r-1][c]=a[r][c];
        for(int c=j+1;c<n;c++) prime[r-1][c-1]=a[r][c];
    }
    return (((((i+j)%2)==0)?1:-1)*determinant(prime,n-1));
}
