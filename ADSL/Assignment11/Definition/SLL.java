package Definition;
import Declaration.Interface;
import java.util.Scanner;

class node
{
	public int data;
	public node next;
	node()
	{
		data=0;
	}
	node(int d)
	{
		data=d;
		next=null;
	}
}
public class SLL implements Interface 
{
node head;
node tail;
int size;

SLL()
{
	head=null;
	tail=null;
	size=0;
}
	public void insert(int x){
		node temp = new node(x);
		size++;
		if(head==null){
			head=temp;
			tail=temp;
    	}
		else{
			tail.next=temp;
			tail=temp;
		}
	}
	
	public int cnt_size(){
		return size;
	}
	
	public int isempty(){
		if(head==null){
			return 0;
		}
		else {
			return 1;
		}
	}
	
	public void display(){
		if(head==null){
			System.out.println("Linked List is Empty!!");
		}
		node temp= head;
		while(temp!=null){
			System.out.print(+temp.data + "->");
			temp=temp.next;
		}
	}
	
	public void delete(int x){
		int flag=0;
		if(head.data==x){
			node temp =head;
			head=head.next;
			temp=null;
			System.gc();
		}
		else{
			node p=head;
			node q=head;
			while(p.data!=x){
				q=p;
				p=p.next;
				if(p==null){
					flag=1;
					break;
				}
			}
			
			if(flag==1){
				System.out.println("Data not present!!");
			}
			else{
				size--;
				q.next=p.next;
				p=null;
				System.gc();
			}
		}
	}
	
	public static void main(String[] args){
		SLL s= new SLL();
		int op,flag=0,data;
		Scanner obj= new Scanner(System.in);
		while(flag!=1){
			System.out.println("\n1.Insert \n2.IsEmpty \n3.Display \n4.Delete \n5.Size \n6.Exit \n Enter your choice-:");
			op=obj.nextInt();
			
			switch(op)
			{
			case 1:
				System.out.println("Enter data to be inserted-: ");
				data=obj.nextInt();
				s.insert(data);
				break;
				
			case 2:
				data=s.isempty();
				if(data==0)
				{
					System.out.println("Linked List is Empty!!");
				}
				else
				{
					System.out.println("Linked List is not Empty!!");
				}
				break;
				
			case 3:
				s.display();
				break;
				
			case 4:
				System.out.println("Enter data to be deleted-: ");
				data=obj.nextInt();
				s.delete(data);
				break;
				
			case 5:
				data=s.cnt_size();
				System.out.println("Size of Linked List is-: "+ data);
				break;
				
			case 6:
				flag=1;
				break;
				
				default:
					System.out.println("Enter valid choice!!");
			}
		}
	}
}
