import java.util.*;

public class A13 {
	Scanner obj= new Scanner(System.in);
	void main_func()
	{
		int op,flag=0;
		while(flag!=1)
		{
			System.out.println("\n1.Linked List \n2.Stack \n3.Priority Queue \n4.Dequeue \n5.HashSet \n6.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			Linked();
			break;
			
		case 2:
			Stack();
			break;
			
		case 3:
			Queue();
			break;
			
		case 4:
			Dequeue();
			break;
			
		case 5:
			HashSet();
			break;
			
		case 6:
			flag=1;
			return;
			
			
			default:
				System.out.println("Enter valid choice!!");
				break;
		}
		}
	}
	
	public void Linked()
	{
		LinkedList<Integer> l= new LinkedList<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add First \n2.Add Last \n3.Remove First \n4.Remove Last \n5.Display whole list \n6.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			l.addFirst(data);
			break;
			
		case 2:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			l.addLast(data);
			break;
			
		case 3:
			l.removeFirst();
			break;
			
		case 4:
			l.removeLast();
			break;
			
		case 5:
			System.out.println("Contents of Linked List are-: "+l);
			break;
			
		case 6:
			flag=1;
			break;
			
			default:
				System.out.println("Enter valid choice!!");
				break;
		}
		}

		//main_func();
	}
	
	public void Stack()
	{
		Stack<Integer> st=new Stack<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Push \n2.Pop \n3.Display Top \n4.IsEmpty \n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			st.push(data);
			break;
			
		case 2:
			System.out.println("Data popped from stack is-: " +st.pop());
			break;
			
		case 3:
			System.out.println("Data at top of stack is-: " +st.peek());
			break;
			
		case 4:
			if(st.isEmpty())
			{
				System.out.println("Stack is Empty!!");
			}
			else
			{
				System.out.println("Stack is not empty!!");
			}
			break;
		case 5:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public void Queue()
	{
		PriorityQueue<Integer> pq= new PriorityQueue<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add Data \n2.Pop \n3.Display head \n4.size \n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in Priority Queue-: ");
			data=obj.nextInt();
			pq.add(data);
			break;
			
		case 2:
			System.out.println("Data popped from Priority Queue is-: " +pq.poll());
			break;
			
		case 3:
			System.out.println("Data at top of Priority Queue is-: " +pq.peek());
			break;
			
		case 4:
			System.out.println("Size of Priority Queue is-: " +pq.size());
			break;
		case 5:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public void Dequeue()
	{
		ArrayDeque<Integer> dq= new ArrayDeque<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add First \n2.Add last \n3.Display head \n4.Display Tail \n5.Remove First \n6.Remove Last \n7.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in Deque-: ");
			data=obj.nextInt();
			dq.addFirst(data);
			break;
			
		case 2:
			System.out.println("Enter data to be added in Deque-: ");
			data=obj.nextInt();
			dq.addLast(data);
			break;
			
		case 3:
			System.out.println("Element at first position is-:  "+dq.peekFirst());
			break;
			
		case 4:
			System.out.println("Element at last position is-:  "+dq.peekLast());
			break;
			
		case 5:
			System.out.println("Data removed from front is-: " +dq.pollFirst());
			break;
			
		case 6:
			System.out.println("Data removed from Last is-: " +dq.pollLast());
			break;
			
		case 7:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public void HashSet()
	{
		HashSet<Integer> hs= new HashSet<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add element \n2.Remove element \n3.Display whole \n4.size\n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in HashSet-: ");
			data=obj.nextInt();
			hs.add(data);
			break;
			
		case 2:
			System.out.println("Enter data to be removed from Deque-: ");
			data=obj.nextInt();
			hs.remove(data);
			break;
			
		case 3:
			System.out.println("Elements in whole Hashset are-:  "+hs);
			break;
			
		case 4:
			System.out.println("Size of HashSet is-:  "+hs.size());
			break;
			
		case 5:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public static void main(String[] args)
	{
		A13 d= new A13();
		d.main_func();
	}
}
