class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def insert_at_position(self, data, position):
        if position <= 0:
            print("Invalid position")
            return
        if position == 1:
            self.insert_at_beginning(data)
            return
        new_node = Node(data)
        current = self.head
        count = 1
        while current and count < position - 1:
            current = current.next
            count += 1
        if not current:
            print("Invalid position")
            return
        new_node.next = current.next
        current.next = new_node

    def delete_at_position(self, position):
        if position <= 0 or not self.head:
            print("Invalid position")
            return
        if position == 1:
            self.head = self.head.next
            return
        current = self.head
        count = 1
        while current and count < position - 1:
            current = current.next
            count += 1
        if not current or not current.next:
            print("Invalid position")
            return
        current.next = current.next.next

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Create an empty linked list
my_linked_list = LinkedList()

# Insert elements at different positions
my_linked_list.insert_at_beginning(10)
my_linked_list.insert_at_end(20)
my_linked_list.insert_at_end(30)
my_linked_list.insert_at_position(15, 2)

# Display the linked list
print("Linked List:")
my_linked_list.display()

# Delete an element at a specific position
my_linked_list.delete_at_position(3)

# Display the updated linked list
print("Updated Linked List:")
my_linked_list.display()
