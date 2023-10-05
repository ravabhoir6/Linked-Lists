class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
    
a = Node(11)
b = Node(9)
c = Node(6)
d = Node(12)
e = Node(3)

a.next = b
b.next = c
c.next = d
d.next = e



def printLinkedList(head):
    current = head
    while current != None:
        print(current.value)
        current = current.next
        
        
def sumLinkedList(head):
    Sum = 0
    current = head
    while current != None:
        Sum += current.value
        current = current.next
    print(Sum)
    
        
def findElementLinkedList(head, value):
    current = head
    while current != None:
        if current.value == value:
            print("present")
        current = current.next
        

def getNodeByIndex(head, index):
    count = 0
    current = head
    while current != None:
        if count == index:
            print(current.value)
        current = current.next
        count += 1
    

def reverseLinkedList(head):
    current = head
    prev = None
    while current != None:
        temp = current.next
        current.next = prev
        prev = current
        current = temp
        
    printLinkedList(prev)
    return prev


def zipperList(head1, head2):
    tail = head1
    current1 = head1.next
    current2 = head2
    count = 0
    while current1 != None and current2 != None:
        if count % 2 ==0:
            tail.next = current2
            current2 = current2.next
        else:
            tail.next = current1
            current1 = current1.next
        
        count += 1
        tail = tail.next
    
    if current1 != None: tail.next = current1
    if current2 != None: tail.next = current2
    
    return tail
        
    
    
    