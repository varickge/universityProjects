#include <iostream>

size_t _count=0;

class ListNode 
{ 
    public:
        ListNode(const double data)
        {
            _data = data;
            _nextPtr = nullptr;
        };

        double _data;
        ListNode* _nextPtr;
};

class List { 
    public:
        List()
        {
            _firstPtr = nullptr; 
            _lastPtr = nullptr;
        };

        ~List()
        {
            ListNode* current = _firstPtr;            
            while( current != nullptr )
            {
                ListNode* next = current->_nextPtr;          
                delete current;     
                current = next;                  
            }
        };

        void insertAtFront(const double value)
        {
            ListNode* new_node = getNewNode(value);
            if( isEmpty() )
            {
                _firstPtr = _lastPtr = new_node;
            }
            else 
            {            
                new_node->_nextPtr = _firstPtr;
                _firstPtr = new_node;
            }
            _count++;
        }; 

        void insertAtBack(const double value)
        {
            ListNode* new_node = getNewNode(value);
            if( isEmpty() )
            {
                _firstPtr = new_node;
                _lastPtr = new_node;
            }
            else 
            {
                _lastPtr->_nextPtr = new_node;
                _lastPtr = new_node;
            }
            _count++;
        }; 

        bool insertAtIndex(const size_t idx, const double value)
        {
            if(idx > 0 && idx <= _count && !isEmpty())
            {
                ListNode* temp = _firstPtr;
                for(int t = 0; t < idx-1; t++)
                {
                    temp = temp->_nextPtr;
                }
                ListNode* new_node = getNewNode(value);
                ListNode* next = temp->_nextPtr;
                temp->_nextPtr = new_node;
                new_node->_nextPtr = next;
                _count++;
                return true;
            }
            else if (isEmpty() || idx == 0)
            {
                insertAtFront(value);
                _count++;
                return true;
            }
            else
            {
                std::cout << "Incorrect index" << std::endl;
            }
            return false;
        };

        bool removeFromFront(double& retval)
        {
            if( _firstPtr != nullptr )
            {
                retval = _firstPtr->_data;
                ListNode* current = _firstPtr;
                _firstPtr = _firstPtr->_nextPtr;
                delete current;
                _count--;
                return true;
            }
            return false;
        }; 

        bool removeFromBack(double& retval)
        {
            ListNode* last = _lastPtr;
            if (isEmpty())
            {
                return false;
            }
            else if(_firstPtr == _lastPtr)
            {
                _firstPtr = _lastPtr = nullptr;
            }
            else if( _lastPtr != nullptr )
            {
                retval = _lastPtr->_data;
                ListNode* temp = _firstPtr;
                while( temp->_nextPtr != last )
                {
                    temp = temp->_nextPtr;
                }
                temp->_nextPtr=nullptr;
                _lastPtr = temp;
            }
            delete last;
            _count--;
            return true;
        };

        bool isEmpty() const
        {
            return (_firstPtr == nullptr);
        };

        void print() const
        {
            ListNode* current = _firstPtr;
            while (current != nullptr) 
            {
                std::cout << current->_data << " ";
                current = current->_nextPtr;
            }
            std::cout << std::endl;
        }; 

        int getElementCount() const
        {
            return _count;
        }

    private:
        ListNode* getNewNode(const double data) const
        {
           ListNode* node = new ListNode(data);
           return node;
        };

    private:
        ListNode* _firstPtr; 
        ListNode* _lastPtr;
};

void instructions() {
    std::cout   << "Enter one of the following:\n"
                << "1 to instert at beginnig of list\n"
                << "2 to insert at end of list\n"
                << "3 to delete from beginning of list\n"
                << "4 to delete from end of list\n"
                << "5 to insert at idx\n"
                << "6 to report the number of elements\n"
                << "7 print list\n"
                << "8 to end list processing\n\n";
}

int switchFun(List& newList) {
    unsigned int a = 0, idx;
    double  data, delData;
    instructions();
    std::cin >> a;
    switch (a)
    {
        case 1: 
        {
            std::cout << "input a double number:" << std::endl;
            std::cin >> data;
            newList.insertAtFront(data);
            break;
        }
        case 2: 
        {
            std::cout << "input a double number:" << std::endl;
            std::cin >> data;
            newList.insertAtBack(data);
            break;
        }
        case 3: 
        {
            std::cout << newList.removeFromFront(delData);
            break;
        }
        case 4: 
        {
            std::cout << newList.removeFromBack(delData);
            break;
        }
        case 5: 
        {
            std::cout << "input a double number:" << std::endl;
            std::cin >> data;
            std::cout << "input the idx:" << std::endl;
            std::cin >> idx;
            newList.insertAtIndex(idx, data);
            break;
        }
        case 6:
        {
            std::cout << newList.getElementCount() << std::endl;
            
        }
        case 7: 
        {
            newList.print();
            break;
        }
        case 8: 
        {
            return 0;
            break;
        }

        default:
            break;
    }

    return switchFun(newList);
}
int main()
{
    List newList;
    switchFun(newList);
}
