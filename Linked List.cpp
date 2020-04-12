/*************************************

		JAHAN FARDA CO
	MOHAMMAD REZA SHAKOURNIA

**************************************/



#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

class node{
	
	friend class linklist;
	char name[21];
	int id;
	float avg;
	struct node *next;
	struct node *prev;
	
	};
	
	class linklist{
		
		public:
			linklist();
			~linklist();
			void addnode();
			void delnode(int &);
			void sort();
			void reverse(char name);
			void display();
			int count;
			
			private:
				node *first;
				node *last;
							
	};
	
	linklist::linklist()
	{
		first=last=NULL;
		
	}
	
	linklist::~linklist(){
		
		node *curptr=first;
		node *temp;
		
		while(curptr){
			temp=curptr;
			curptr=curptr ->next;
			delete temp;
			
		}
	}
	
	void linklist::delnode(int &no){
		
		node *curptr=first,*nextptr=first;
		
		if(nextptr==NULL)
		{
				cout<<"There is no Recorde to Delete!\n\n";
		}
		else{
		
					cout<<"Enter id to delete:";
					cin>>no;
					
					
				while(nextptr)
				{
					if(no==nextptr -> id)
						if(nextptr==first)
						{
							first=first->next;
							delete nextptr;
							break;
						}
						else {
							
							if(nextptr==last)
								last=curptr;
							curptr -> next=nextptr-> next;
							delete nextptr;
							break;	
							
							}
						else {
							
						curptr= 
						nextptr;
						nextptr=nextptr -> next;
							}
				}
		}
		cout<<"Record Deleted.\n\n";

	}
	
		void linklist::reverse(char name)
	{
				
		
		    struct node *p1, *p2;
		
		    p1 = first;
		
		    p2 = p1->next;
		
		    p1->next = NULL;
		
		    p1->prev = p2;
		
		    while (p2 != NULL)
		
		    {
		
		        p2->prev = p2->next;
		
		        p2->next = p1;
		
		        p1 = p2;
		
		        p2 = p2->prev; 
		
		    }
		
		    first = p1;
		
		    cout<<"List Reversed"<<endl; 
		
		}
		

	void linklist::addnode()
	{
		
		node *newptr=new node;
		
		if(!newptr)
		{
			getch();
		}
		
		newptr->next=NULL;
		cout<<"Name:\n";
		count++;
		cin>>newptr -> name;
		
		
		cout<<"ID:\n";
		cin>>newptr -> id;
		
		cout<<"Avegrage: \n";
		cin>>newptr ->avg;
		cout<<"\n";

			if(first==NULL)
			first=last=newptr;
			else{
				last ->next=newptr;
				last=newptr;
			}
	}
	
	void linklist::sort()
	{
		node*newptr=first;
		node*idptr=first;
		node*avgptr=first;
		

	    string s[200],ct;
	    int d[200],dt;
	    float gt,g[200];
	    int i,j;
    
	    for(i=0;i<count-1;i++)
	    {
	        s[i]=newptr->name;
	        d[i]=newptr->id;
	        g[i]=newptr->avg;
	        newptr=newptr->next;
	    }

		    for(i=0;i<count-1;i++)
		    {
		        for(j=i+1;j<count-1;j++)
		        {
		
		            if(s[i]>s[j])
		            {
		
		                ct=s[i];
		                s[i]=s[j];
		                s[j]=ct;
		                dt=d[i];
		                d[i]=d[j];
		                d[j]=dt;
		                gt=g[i];
		                g[i]=g[j];
		                g[j]=gt;
		                
		               
		
		            }
		
		        }
		
		    }
  			  cout<<"\nSorted List:\n"<<endl;
		    for(i=0;i<count-1;i++)
		    {
			       cout<<s[i]<<"\t"<<d[i]<<"\t"<<g[i]<<endl; 
		    }
    }



            
	        
	

	void linklist::display()
	{
		int r=2;
		node *curptr=first;
		if(curptr==NULL)
		{
			cout<<"There is no Recorde to Display!\n";
		}
		else
		{
		
			while(curptr)
			{
	
				cout<<curptr -> name;
		
				cout<<"\t"<<curptr -> id;
		
				cout<<"\t"<<curptr -> avg<<" \t\n\n";
				curptr=curptr->next;
				r++;
			
			}
	
		}

			}
			
			int menu();
			int main(){
				int no;
				char name;
				linklist testlist;
				for(;;)
				{
			
					switch(menu())
					{
						case 1:testlist.addnode();break;
						case 2:testlist.delnode(no);break;
						case 3: testlist.display();break;
						case 4:testlist.sort();break;
						case 5:testlist.reverse(name);break;
						case 6:exit(1);
					}
				}
			}
			int menu(){
				
				int choice;
				
					cout<<"1.Create Node\n";
					cout<<"2.Delete Node\n";
					cout<<"3.Display List\n";
					cout<<"4.Sort\n";
					cout<<"5.Reverse\n";
					cout<<"6.Exit\n";
					cout<<"\nEnter a Choice:";
					
					cin>>choice;
					cout<<"\n";
					return choice;
				
			}
