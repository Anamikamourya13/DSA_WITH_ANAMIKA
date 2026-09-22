class MyHashSet {
public:
    vector<bool> set;

    MyHashSet() {
        set.resize(1000001, false);
    }

    void add(int key) {
        set[key] = true;
    }

    void remove(int key) {
        set[key] = false;
    }

    bool contains(int key) {
        return set[key];
    }
};