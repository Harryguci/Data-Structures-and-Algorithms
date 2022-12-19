
#ifndef HASH
#define HASH

#include <iostream>
using namespace std;
template <class Keys,class T>
class Node{
private:
    Keys key;   
	T elem;
	Node<Keys,T> *next;
public:
	Node() {next = NULL;}
	Keys getKey(){ return key;}
	void setKey(Keys k){ key = k;}
	Node<Keys,T>  *getNext();          //Tra lai dia chi cua doi tuong do thanh phan Next tro den
	void    setNext(Node<Keys,T>*);		//Dat thanh phan Next tro vao doi tuong la doi cua phuong thuc
	T       getElem();			// Tra lai dia chi cua phan tu luu trong Node
	void    setElem(T);	// Dat thay the phan tu luu trong Node bang phan tu moi
};
//------------------------------------------------------------------
template <class Keys,class T>
Node<Keys,T>* Node<Keys,T>::getNext()
{
	return next;
}
//------------------------------------------------------------------
template <class Keys,class T>
void Node<Keys,T>::setNext(Node<Keys,T> * p)
{
	next = p;
}
//------------------------------------------------------------------
template <class Keys,class T>
T Node<Keys,T>::getElem()
{
	return elem;
}
//------------------------------------------------------------------
template <class Keys,class T>
void Node<Keys,T>::setElem(T e)
{
	elem = e;
}
//***************************************************//
template <class Keys, class T>
class SingleList{
private:
	Node<Keys,T> *header;	
	Node<Keys,T> *trailer; 
	long sz;
public:
	SingleList();
	long   size();
	int    isEmpty();
	Node<Keys,T>* insertLast(Keys key,T e);  //Chen them mot node vao cuoi danh sach
	void replace(Node<Keys,T>* p,Keys k, T e);
    void remove(Node<Keys,T> *p);		 // Loai bo node do con tro p tro toi
	Node<Keys,T>* getNode(Keys k);
};
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
SingleList<Keys,T>::SingleList()
{
	header	= NULL;
	trailer = NULL;
	sz		= 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
long SingleList<Keys,T>::size ()
{
	return sz;
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
int SingleList<Keys,T>::isEmpty()
{
	return header == NULL;	
}
// Thay the phan tu luu trong node do co dia chi luu trong p bang phan tu co gia tri e
template <class Keys, class T>
void SingleList<Keys,T>::replace(Node<Keys,T>* p,
                                         Keys k, T e)
{
	p->setKey(k);
	p->setElem(e);
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
Node<Keys,T>* SingleList<Keys,T>::insertLast(Keys k, T e)
{
	Node<Keys,T> *q;
	q = new Node<Keys,T>;
	q->setKey(k);
	q->setElem(e);
	if(header==NULL)
	{
		header = q;
		trailer= q;
	}
	else{
		trailer->setNext(q);
		trailer = q;
	}
	sz++;
	return q;
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
void SingleList<Keys,T>:: remove(Node<Keys,T>* p)
{
	Node<Keys,T> *p1;
	if(p==header)
	{
		if(size()==1)
		{
			header = NULL;
			trailer = NULL;
		}
		else
			header = header->getNext();
		sz--;
	}
	else
	{
		p1	= header;
		while(p1->getNext()!=p)			// Vong lap tim den vi tri cua node truoc node p
			p1 = p1->getNext();
		if(p1!=NULL)
		{					//Tim thay node can xoa
			if(p!=trailer)
				p1->setNext(p->getNext());
			else{
				trailer = p1;
				p1->setNext(NULL);
			}
			sz--;
		}
	}
	delete p;
}
template <class Keys, class T>
 Node<Keys,T>* SingleList<Keys,T>::getNode(Keys k)
 {
	Node<Keys,T> *p;
	p = header;
	while(p!=NULL && p->getKey()!=k)
	  p = p->getNext();
	return p;
 }
//-------------**************************----------------------------------------
template<class Keys,class T>
class Hashtable
{
	 private:
		 int N;
		 SingleList<Keys,T> *table;
	 public:
		 Hashtable(int n);
		 Node<Keys,T> *Add(Keys key, T obj,  int (*hash)(Keys,int));
		 void Remove(Keys key, int (*hash)(Keys,int));
		 Node<Keys,T> * Find(Keys key, int (*hash)(Keys,int));
		 int Contains(Keys key, int (*hash)(Keys,int));
		 int Count();
};
template<class Keys,class T>
Hashtable<Keys,T>::Hashtable(int n)
 {
		N = n;
		table=  new SingleList<Keys,T>[N];
 }
template<class Keys,class T>
Node<Keys,T>* Hashtable<Keys,T>::Add(Keys key, T obj, 
                                  int (*hash)(Keys,int))
{
	  Node<Keys,T> *p;
	  int h = hash(key,N); //hash la mot con tro ham
	  p = table[h].getNode(key);
	  if(p==NULL)
		 return table[h].insertLast(key,obj);
	  else
		 return NULL;
 }
template<class Keys,class T>
void Hashtable<Keys,T>::Remove(Keys key, 
                                 int (*hash)(Keys,int))
{
	 int h = hash(key,N);
	 Node<Keys,T> *p;
	 p = table[h].getNode(key);
	 if(p!=NULL)
		 table[h].remove(p);
}
template<class Keys,class T>
Node<Keys,T> * Hashtable<Keys,T>::Find(Keys key, 
                                int (*hash)(Keys,int))
{
	 int h = hash(key,N);
	 return  table[h].getNode(key);
}
template<class Keys,class T>
int Hashtable<Keys,T>::Contains(Keys key, int (*hash)(Keys,int))
{
	 int h = hash(key,N); //hash la mot con tro ham
	 if(table[h].getNode(key)==NULL)
		 return 0;
	 else
		 return 1;
}
template<class Keys,class T>
int Hashtable<Keys,T>::Count()
{
	  int t = 0;
	  for(int i=0;i<N;i++)
		 t = t + table[i].size();
	  return t;
}
int h(int key, int n)
{
	 return key % n;
}

#endif // !1
//
//int main()
//{
//	  Hashtable<int, float> ht(97);
//	  Node<int,float> *p;
//	  int key;
//
//	  ht.Add(1,45.5,h);
//	  ht.Add(3,4.23,h);
//	  ht.Add(100,50.23,h);
//	  ht.Add(10,100.23,h);
//	  cout<<"\nSo phan tu hien co trong bang bam " 
//         <<ht.Count();
//	  cout<<"\nNhap khoa can tim: ";
//	  cin>>key;
//	  p=ht.Find(key,h);
//	  if(p==NULL)
//		  cout<<"\nKhong tim thay phan tu co khoa = "<<key;
//	  else
//		  cout<<"\nTim thay phan tu co khoa = "<<key
//		  <<"\nGia tri cua no = "<<p->getElem();
//	  return 0;
//}
