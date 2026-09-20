class LRUCache {
public:

    class node {
    public:
        int key, val;
        node* prev;
        node* next;

        node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    unordered_map<int, node*> m;
    int limit;

    // Insert node immediately after head
    void addnode(node* newnode) {
        node* oldnode = head->next;

        newnode->next = oldnode;
        newnode->prev = head;

        head->next = newnode;
        oldnode->prev = newnode;
    }

    // Remove node from linked list
    void delnode(node* oldnode) {
        node* oldprev = oldnode->prev;
        node* oldnext = oldnode->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }

        node* ansnode = m[key];
        int ans = ansnode->val;

        // Remove from current position
        delnode(ansnode);

        // Put at front = most recently used
        addnode(ansnode);

        return ans;
    }

    void put(int key, int value) {

        // Key already exists
        if (m.find(key) != m.end()) {

            node* oldnode = m[key];

            // Update value
            oldnode->val = value;

            // Move to front
            delnode(oldnode);
            addnode(oldnode);

            return;
        }

        // Cache is full
        if (m.size() == limit) {

            // Least recently used node
            node* lru = tail->prev;

            m.erase(lru->key);
            delnode(lru);

            delete lru;
        }

        // Insert new node at front
        node* newnode = new node(key, value);

        addnode(newnode);
        m[key] = newnode;
    }
};