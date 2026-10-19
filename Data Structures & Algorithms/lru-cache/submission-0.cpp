class LRUCache {
    struct Node
    {
        int key = 0, val = 0;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(int k, int v) : key(k), val(v) {}
    };
	Node* head = new Node(0, 0);
	Node* tail = new Node(0, 0);
    int cap = 0;
    unordered_map<int, Node*> Map;
    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;             
    }
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!Map.contains(key))
            return -1;
        else
        {
            Node* node = Map[key];
            removeNode(node);
            insertFront(node);
            return node->val;
        }
    }

    

    void put(int key, int value)
    {
        if (Map.contains(key))
        {
            Node* node = Map[key];
            node->val = value;
            removeNode(node);
            insertFront(node);
            return;
        }

        Node* node = new Node(key, value);
        Map[key] = node;
        insertFront(node);

        if (Map.size() > cap)
        {
            Node* lru = tail->prev;      
            removeNode(lru);
            Map.erase(lru->key);
            delete lru;
        }
    }
};