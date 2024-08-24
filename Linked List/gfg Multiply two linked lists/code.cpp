class solution {
  public:
    
    const int MOD = 1000000007;

    long long getNumber(Node* head) {
        long long num = 0;
        while (head != nullptr) {
            num = (num * 10 + head->data) % MOD;
            head = head->next;
        }
        return num;
    }

    long long multiplyTwoLists(Node *first, Node *second) {
        // Get the numbers from both linked lists
        long long num1 = getNumber(first);
        long long num2 = getNumber(second);
    
        // Multiply the numbers and take modulo
        long long result = (num1 * num2) % MOD;
    
        return result;
    }
    
};