import java.util.PriorityQueue;

class Node{
    int data;
    Node next;
    Node(int val){
        data=val;
        next=null;
    }
}
public class mergeKSortedList {
    static public Node merge(Node[] arr,int k){

        PriorityQueue<Node> pq=new PriorityQueue<>((a,b)->{
            return a.data-b.data;
        });

        for(int i=0;i<k;i++){
            if(arr[i]!=null){
                pq.add(arr[i]);
            }
        }
        
        if(pq.isEmpty()) return null;

        Node dummy=new Node(-1);
        Node last=dummy;

        while(!pq.isEmpty()){

            Node curr=pq.remove();
            last.next=curr;
            last=last.next;

            if(curr.next!=null){
                pq.add(curr.next);
            }
        }
        return dummy.next;
    }

    static void printList(Node head){
        while(head!=null){
            System.out.print(head.data+" -> ");
            head=head.next;
        }
        System.out.print("none");
    }

    public static void main(String[] args) {
  
        int k=3;
        Node[] arr=new Node[k];

        //Linked List 1: 3->5->7
        arr[0]=new Node(3);
        arr[0].next=new Node(5);
        arr[0].next.next=new Node(7);

        //Linked List 2: 0->6
        arr[1]=new Node(0);
        arr[1].next=new Node(6);

        //Linked List 3: 1->6->28
        arr[2]=new Node(1);
        arr[2].next=new Node(6);
        arr[2].next.next=new Node(28);

        //Calling the merge function to merge all the linked lists
        Node head=merge(arr,k);
        printList(head);
    }
}
