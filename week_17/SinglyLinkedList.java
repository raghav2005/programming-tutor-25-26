public class SinglyLinkedList<T> {

    private static final class Node<T> {
        T value;
        Node<T> next;

        Node(T value) {
            this.value = value;
        }
    }

    private Node<T> head;

    // add to the end of the list
    public void add(T value) {
        Node<T> n = new Node<>(value);

        if (head == null) {
            head = n;
            return;
        }

        Node<T> cur = head;
        while (cur.next != null) {
            cur = cur.next;
        }
        cur.next = n;
    }

    // remove the first occurrence of value; returns true if removed
    public boolean remove(T value) {
        if (head == null) return false;

        // removing head
        if (value == null ? head.value == null : value.equals(head.value)) {
            head = head.next;
            return true;
        }

        Node<T> prev = head;
        Node<T> cur = head.next;

        while (cur != null) {
            if (value == null ? cur.value == null : value.equals(cur.value)) {
                prev.next = cur.next;
                return true;
            }
            prev = cur;
            cur = cur.next;
        }

        return false;
    }

    public boolean isEmpty() {
        return head == null;
    }

    // returns the first matching value, or null if not found
    public T find(T value) {
        Node<T> cur = head;
        while (cur != null) {
            if (value == null ? cur.value == null : value.equals(cur.value)) {
                return cur.value;
            }
            cur = cur.next;
        }
        return null;
    }

    public static void main(String[] args) {
        SinglyLinkedList<Integer> list = new SinglyLinkedList<>();

        System.out.println("Empty? " + list.isEmpty()); // true

        list.add(10);
        list.add(20);
        list.add(30);

        System.out.println("Empty after adds? " + list.isEmpty()); // false

        System.out.println("Find 20: " + list.find(20)); // 20
        System.out.println("Find 99: " + list.find(99)); // null

        System.out.println("Remove 10 (head): " + list.remove(10)); // true
        System.out.println("Find 10 after remove: " + list.find(10)); // null

        System.out.println("Remove 30 (tail): " + list.remove(30)); // true
        System.out.println("Find 30 after remove: " + list.find(30)); // null

        System.out.println("Remove 999 (missing): " + list.remove(999)); // false

        System.out.println("Remove 20 (last item): " + list.remove(20)); // true
        System.out.println("Empty at end? " + list.isEmpty()); // true
    }
}
