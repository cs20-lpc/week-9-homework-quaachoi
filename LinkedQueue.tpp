template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if(isEmpty())
    {
        return T{};
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    head = last = nullptr;
    this->length = 0;

    Node* current = copyObj.head;

    while (current != nullptr) 
    {
        enqueue(current->value);  // use enqueue to maintain last pointer and length
        current = current->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if(this->length == 0)
    {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    this->length--;

    if (head == nullptr) 
    {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);
    if (isEmpty()) 
    {
        head = last = newNode;
    } 
    else 
    {
        last->next = newNode;
        last = newNode;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty()) 
    {
        return T{};
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
