#include<iostream>
using namespace std;

template <class type>

struct SNode {
   type* element;
   SNode *next;

   SNode(type* e, SNode* n)  {
      element = e;
      next = n;
   }
   type* getElement() { return element; }
   void print() { cout << *element<< "  "; }
};

template <class type>

class SList {
protected:		// data member
    SNode<type> * head;
    long size;		// number of nodes in the list

public:
    SList() {
        head = NULL;
        size = 0;
    }
    long getSize() { return size; }
    int isEmpty() { return size<=0; }

    SNode<type>* addFirst(type* s) { // push
        SNode<type>* newNode = new SNode<type>(s, head);
        head = newNode;
        size++;
        return newNode;
    }

    type* removeFirst() { // pop
        if (head==NULL) return NULL;
        else{
        	SNode<type> * temp = head;
        	head = head -> next;
        	type * x = temp->element;
        	delete temp;
        	size--;
        	return x;
		}
    }

    type * returnFirst(){ // front
    	if(head != NULL)
    		return head->element;
    }

    void print() {
        SNode<type>* iter = head;
        while (iter!=NULL) {
            iter->print();
            iter = iter->next;
        }
        cout << endl;
    }
};

int main(){
	SList<int> *sl_int = new SList<int>();
	int a1 = 3,a2= 8, a3=10,a4=1;
	sl_int->addFirst(&a1);
	sl_int->addFirst(&a2);
	sl_int->addFirst(&a3);
	sl_int->addFirst(&a4);
	sl_int->print();
	sl_int->removeFirst();
	sl_int->print();
	cout << endl;

	SList<float> *sl_float = new SList<float>();
	float b1 = 3.2,b2= 8.0, b3= 1.2,b4=5.5;
	sl_float->addFirst(&b1);
	sl_float->addFirst(&b2);
	sl_float->addFirst(&b3);
	sl_float->addFirst(&b4);
	sl_float->print();
	sl_float->removeFirst();
	sl_float->print();
	cout << endl;

	SList<char*> *sl_char = new SList<char*>();
	char* c1 = "123";
	char* c2 = "456";
	sl_char->addFirst(&c1);
	sl_char->addFirst(&c2);
	sl_char->print();

	return 0;
}
