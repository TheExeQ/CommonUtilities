#pragma once

namespace CommonUtilities
{
	template <class T>
	class DoublyLinkedList;

	template <class T>
	class DoublyLinkedListNode
	{
	public:
		DoublyLinkedListNode<T>(const DoublyLinkedListNode<T>&) = delete;
		DoublyLinkedListNode<T>& operator=(const DoublyLinkedListNode<T>&) = delete;

		const T& GetValue() const;
		T& GetValue();
		DoublyLinkedListNode<T>* GetNext() const;
		DoublyLinkedListNode<T>* GetPrevious() const;

	private:
		friend class DoublyLinkedList<T>;
		DoublyLinkedListNode(const T& aValue);
		~DoublyLinkedListNode() {}

		T value;
		DoublyLinkedListNode<T>* prev;
		DoublyLinkedListNode<T>* next;
	};

	template <class T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		int GetSize() const;
		DoublyLinkedListNode<T>* GetFirst();
		DoublyLinkedListNode<T>* GetLast();
		void InsertFirst(const T& aValue);
		void InsertLast(const T& aValue);
		void InsertBefore(DoublyLinkedListNode<T>* aNode, const T& aValue);
		void InsertAfter(DoublyLinkedListNode<T>* aNode, const T& aValue);
		void Remove(DoublyLinkedListNode<T>* aNode);
		DoublyLinkedListNode<T>* FindFirst(const T& aValue);
		DoublyLinkedListNode<T>* FindLast(const T& aValue);
		bool RemoveFirst(const T& aValue);
		bool RemoveLast(const T& aValue);

	private:
		DoublyLinkedListNode<T>* myHead;
		DoublyLinkedListNode<T>* myTail;
		int myCount;
	};

	template <class T>
	CommonUtilities::DoublyLinkedListNode<T>::DoublyLinkedListNode(const T& aValue)
	{
		value = aValue;
	}

	template <class T>
	CommonUtilities::DoublyLinkedListNode<T>* CommonUtilities::DoublyLinkedListNode<T>::GetPrevious() const
	{
		return prev;
	}

	template <class T>
	CommonUtilities::DoublyLinkedListNode<T>* CommonUtilities::DoublyLinkedListNode<T>::GetNext() const
	{
		return next;
	}

	template <class T>
	T& CommonUtilities::DoublyLinkedListNode<T>::GetValue()
	{
		return value;
	}

	template <class T>
	const T& CommonUtilities::DoublyLinkedListNode<T>::GetValue() const
	{
		return value;
	}

	template <class T>
	bool CommonUtilities::DoublyLinkedList<T>::RemoveLast(const T& aValue)
	{
		auto* node = myTail;
		if (!node) { return false; }
		do
		{
			if (node->value == aValue)
			{
				if (node != myHead && node != myTail)
				{
					node->prev->next = node->next;
					node->next->prev = node->prev;
					delete node;
					myCount--;
					return true;
				}
				else if (node == myHead)
				{
					if (node->next) { node->next->prev = nullptr; }
					if (myTail == myHead) { myTail = nullptr; }
					myHead = node->next;
					delete node;
					myCount--;
					return true;
				}
				else if (node == myTail)
				{
					if (node->prev) { node->prev->next = nullptr; }
					if (myHead == myTail) { myHead = nullptr; }
					myTail = node->prev;
					delete node;
					myCount--;
					return true;
				}
			}
			node = node->prev;

		} while (node != nullptr);
		return false;
	}

	template <class T>
	bool CommonUtilities::DoublyLinkedList<T>::RemoveFirst(const T& aValue)
	{
		auto* node = myHead;
		if (!node) { return false; }
		do
		{
			if (node->value == aValue)
			{
				if (node != myHead && node != myTail)
				{
					node->prev->next = node->next;
					node->next->prev = node->prev;
					delete node;
					myCount--;
					return true;
				}
				else if (node == myHead)
				{
					if (node->next) { node->next->prev = nullptr; }
					if (myTail == myHead) { myTail = nullptr; }
					myHead = node->next;
					delete node;
					myCount--;
					return true;
				}
				else if (node == myTail)
				{
					if (node->prev) { node->prev->next = nullptr; }
					if (myHead == myTail) { myHead = nullptr; }
					myTail = node->prev;
					delete node;
					myCount--;
					return true;
				}
			}
			node = node->next;

		} while (node != nullptr);
		return false;
	}

	template <class T>
	CommonUtilities::DoublyLinkedListNode<T>* CommonUtilities::DoublyLinkedList<T>::FindLast(const T& aValue)
	{
		auto* node = myTail;
		do
		{
			if (node->value == aValue)
			{
				return node;
			}
			node = node->prev;

		} while (node != nullptr);
		return nullptr;
	}

	template <class T>
	CommonUtilities::DoublyLinkedListNode<T>* CommonUtilities::DoublyLinkedList<T>::FindFirst(const T& aValue)
	{
		auto* node = myHead;
		do
		{
			if (node->value == aValue)
			{
				return node;
			}
			node = node->next;

		} while (node != nullptr);
		return nullptr;
	}

	template <class T>
	void CommonUtilities::DoublyLinkedList<T>::Remove(DoublyLinkedListNode<T>* aNode)
	{
		if (!aNode) { return; }
		if (aNode != myHead && aNode != myTail)
		{
			aNode->prev->next = aNode->next;
			aNode->next->prev = aNode->prev;
			delete aNode;
			myCount--;
		}
		else if (aNode == myHead)
		{
			aNode->next->prev = nullptr;
			myHead = aNode->next;
			delete aNode;
			myCount--;
		}
		else if (aNode == myTail)
		{
			aNode->prev->next = nullptr;
			myTail = aNode->prev;
			delete aNode;
			myCount--;
		}
	}

	template <class T>
	void CommonUtilities::DoublyLinkedList<T>::InsertAfter(DoublyLinkedListNode<T>* aNode, const T& aValue)
	{
		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		newNode->prev = aNode;
		newNode->next = aNode->next;
		if (newNode->next != nullptr) newNode->next->prev = newNode;
		else { myTail = newNode; }
		if (newNode->prev != nullptr) newNode->prev->next = newNode;
		myCount++;
	}

	template <class T>
	void CommonUtilities::DoublyLinkedList<T>::InsertBefore(DoublyLinkedListNode<T>* aNode, const T& aValue)
	{
		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		newNode->prev = aNode->prev;
		newNode->next = aNode;
		if (newNode->next != nullptr) newNode->next->prev = newNode;
		if (newNode->prev != nullptr) newNode->prev->next = newNode;
		else { myHead = newNode; }
		myCount++;
	}

	template <class T>
	void CommonUtilities::DoublyLinkedList<T>::InsertLast(const T& aValue)
	{
		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		newNode->prev = myTail;
		newNode->next = nullptr;
		myTail = newNode;
		if (!newNode->prev) { myHead = myTail; }
		else { myTail->prev->next = myTail; }
		myCount++;
	}

	template <class T>
	void CommonUtilities::DoublyLinkedList<T>::InsertFirst(const T& aValue)
	{
		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		newNode->prev = nullptr;
		newNode->next = myHead;
		myHead = newNode;
		if (!newNode->next) { myTail = myHead; }
		else { myHead->next->prev = myHead; }
		myCount++;
	}

	template <class T>
	CommonUtilities::DoublyLinkedListNode<T>* CommonUtilities::DoublyLinkedList<T>::GetLast()
	{
		return myTail;
	}

	template <class T>
	CommonUtilities::DoublyLinkedListNode<T>* CommonUtilities::DoublyLinkedList<T>::GetFirst()
	{
		return myHead;
	}

	template <class T>
	int CommonUtilities::DoublyLinkedList<T>::GetSize() const
	{
		return myCount;
	}

	template <class T>
	CommonUtilities::DoublyLinkedList<T>::~DoublyLinkedList()
	{
		DoublyLinkedListNode<T>* currentNode;
		if (!myHead && !myTail) { return; }
		else if (myTail)
		{
			currentNode = myTail;
			while (currentNode->prev)
			{
				currentNode = currentNode->prev;
				if (!currentNode->next) { delete currentNode->next; }
			}
			delete myTail;
		}
		else
		{
			currentNode = myHead;
			while (currentNode->next)
			{
				currentNode = currentNode->next;
				if (!currentNode->prev) { delete currentNode->prev; }
			}
			delete myHead;
		}
	}

	template <class T>
	CommonUtilities::DoublyLinkedList<T>::DoublyLinkedList()
	{
		myHead = nullptr;
		myTail = nullptr;
		myCount = 0;
	}

}