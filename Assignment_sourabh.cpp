#include <bits/stdc++.h> 
using namespace std; 
#define MAX 10000
  
struct Node { 
    string data=""; 
    struct Node* children[MAX]; 
    int size;
    int limit;

    Node(string val) 
    { 
        data = val; 
        for(int i=0 ; i<MAX; i++)
        {
        	children[i]=NULL;
        }
        size=0;
    	limit=0;
    } 
}; 

int size(Node* node)  
{  
	int ans=0;
    if (node == NULL)  
        ans= 0;  
    else
    {
        for(int i=0 ; i<node->limit; i++)  
        {
        	ans+=size(node->children[i]);

        }
    }
    node->size= ans+1;
    return node->size;
}  
void addnode( Node* root , string value)
{
	Node *latest = new Node(value);

	int index = root-> limit;
	root->children[index+1]= latest;
	root->limit= index+1;
}
void maketree( Node* root, string str)
{
	int n = str.length();
	int i=0 ;
	int j=0;
	string value="";
	Node*ptr=root;
	while(i<n)
	{
		if(str[i]!='^'|| i!=n-1)
		{
			i++;
		}
		else if(str[i]=='^')
		{
			for( int k=j ; k<=i ; k++)
			{
				value+=str[k];
				

			}
			if(ptr->data==value)
			{
				i++;
				j=i;
			}
			else
			{
				bool find = false;
				int lmt= ptr->limit;
				for( int i=0 ; i< lmt ; i++)
				{
					if( ptr->children[i]->data==value)
					{
						find ==true;
						ptr =  ptr->children[i];
					}
				}

				if( find == false)
				{
					addnode( ptr, value);
				}
			}


			
		}
		else if( i==n-1)
		{
			for( int k=j ; k<=i ; k++)
			{
				value+=str[k];
			}
		}
	}

}
  
int main() 
{ 
  #ifndef ONLINE_JUDGE
		 freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
   #endif

   int n;
   cin>>n;
   for( int i=0 ;i< n ; i++)
   {
   		string str;
   		cin>>str;

   		int len = str.length();

   } 
    
    
} 