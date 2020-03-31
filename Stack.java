import java.util.*;
public class Stack {
	
	
	static Scanner sc = new Scanner(System.in);
	static int stack[],top = -1,item, size;
	static 
	{
		Stack.create();
		
	}
	public static void main(String []args)
	{
		 int choice; 
		while(true)
		{
		   System.out.println("1:Push");
		   System.out.println("2.Pop");
		   System.out.println("3.Peek");
		   System.out.println("4.Travers");
		   System.out.println("5.Exit");
		   
		 System.out.print("Enter Your choice:");
		 choice = Stack.sc.nextInt();
		
		switch(choice)
		 {
		case 1:
			System.out.println("Enter the element to push:");
			item = sc.nextInt();
			 Stack.Push(item);
			  break;
		case 2:
			item = Stack.Pop();
			if(item == 0)
			{
				System.out.println("Stack is underflow\n");
			}else{
				System.out.println("The Poped ite is "+item);
			}
			break;
		case 3:
             item = Peek();
             if(item == 0)
 			{
 				System.out.println("Stack is underflow\n");
 			}else{
 				System.out.println("The Peek item is "+item);
 			}
			break;
		case 4:
			 Travers();
			break;
		case 5:
			System.exit(1);
			default:
				System.out.println("Invalid choice:");
		
		 }
			
		}
	}
	static void create()
	{
		
		System.out.println("Enter the Size of stack:");
	    size = Stack.sc.nextInt();
	    Stack.stack = new int[size];
	    System.out.println("Stack is Created of Size "+size);
	}
	static boolean isEmpty()
	{
		if(top == -1)
		{
			return true;
		}else
		{
			return false;
		}
	}
	static boolean isFull()
	{
		if(top == size-1)
		{
			return true;
		}else
		{
			return false;
		}
	}
	static void  Push(int item)
	{
		if(Stack.isFull())
		{
			System.out.println("Stack is Overflow");
		}else
		{
			stack[++top] = item;
			
			
		}
	
	}
	static int  Pop()
	{
		if(Stack.isEmpty())
		{
			 return 0;
		}else
		{
			return stack[top--];
		}
	}
	static int  Peek()
	{
		if(Stack.isEmpty())
		{
			 return 0;
		}else
		{
			return stack[top];
		}
	}
	static void Travers()
	{
		if(Stack.isEmpty())
		{
		  System.out.println("Stack is Empty");
		}else{
			System.out.println("Element of stack is :");
			for(int i = top; i>=0; i--)
			{
				System.out.println(stack[i]);
			}
		}
		
	}

}
