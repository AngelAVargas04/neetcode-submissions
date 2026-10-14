class node {
public:
    node* next;
    int data;   

    node(int val) {
        data = val;
        next = nullptr;
    }
};


class LinkedList {
private:
    node* head = nullptr;
    node* tail = nullptr;
public:
    LinkedList() {

    }

    int get(int index) {
        node* current = head;
        int count = 0;

        while(current != nullptr)
        {
            if(count == index)
            {
                return current->data;
            }
            count++;
            current = current->next;
        }
        return -1; // if it can't find it.
    }

    void insertHead(int val) {
        node* addfront = new node(val);

        if(head == nullptr)
        {
            head = addfront;
            tail = addfront;
        }
        else
        {
            addfront->next = head;
            head = addfront;
        }
    }
    
    void insertTail(int val) {
        node* addback = new node(val);

        if(head == nullptr)
        {
            head = addback;
            tail = addback;
        }
        else
        {
            tail->next = addback;
            tail = addback;
        }
    }

    bool remove(int index) {

// Guard against empty lists or invalid negative indices
        if(head == nullptr || index < 0) {
            return false;
        }

        // Edge Case: Removing the head node
        if(index == 0) {
            node* temp = head;
            head = head->next;
            
            // If the list is now empty, ensure the tail pointer is also updated
            if(head == nullptr) {
                tail = nullptr;
            }
            
            delete temp;
            return true;
        }

        int i = 0;
        node* current = head;
        
        // Traverse to the node immediately preceding the target index
        while(i < index - 1 && current != nullptr) {
            i++;
            current = current->next;
        }

        // Ensure the target node actually exists before attempting deletion
        if(current != nullptr && current->next != nullptr) {
            if (current->next == tail) {
                tail = current;
            }
            node* del = current->next;
            current->next = current->next->next;
            delete del;
            return true;
        }
        
        return false;
    }   

    vector<int> getValues() {
        vector<int> values;
        node* current = head;
        
        while (current != nullptr) {
            values.push_back(current->data);
            current = current->next;
        }
        
        return values;
    }
};
