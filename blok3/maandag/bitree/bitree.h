
class note {
public:
    note(unsigned long t_timestamp, int t_notenr);

    bool operator< (note b) {
        return this->get_time() < b.get_time();
    }
    bool operator> (note b) {
        return this->get_time() > b.get_time();
    }
    unsigned long get_time();
    void print();
private:
    unsigned long timestamp;
    int notenr;
};
typedef note note;


class node {
public:
    void insert(note* new_note);
    void print();

    node(note* new_cont);
private:
    note* cont;
    node* left;
    node* right;

};
