//T must have the less than operator (bool operation<(const T &other)) defined.
//minVal is the least value T can take under the defined operation <.
//T must have a well defined assignment operator.
template<typename T>
class SkipList{
	struct Node{
		static mt19937 base;
		static uniform_int_distribution<mt19937::result_type> flip; 
		T value;
		//First element in pair is the next node at this level (NULL if end of list). Second is number of
		//elements between the current node and next in this level (not including first, but including next)
		vector<pair<Node*,int>> nextElement;

		Node()=delete;
		Node(T val);
		~Node();
	} *head;
	public:
	SkipList()=delete;
	SkipList(T minVal){
		head=new Node(minVal);
	}
	~SkipList();

	void insert(T ele);

	pair<bool,T> lower_bound(T ele);
	pair<bool,T> upper_bound(T ele);
	//rank must be less than number of elements in the list.
	T find(int rank);

	//Tries to erase first occurrence of ele. Returns true if something was erased, false otherwise.
	bool erase(T ele);

	//Number of elements strictly lesser than toFind
	int rank(T toFind);

	//Splits all nodes <= ele and all nodes > ele
	SkipList split(T ele);
};
template<typename T>
mt19937 SkipList<T>::Node::base(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>
uniform_int_distribution<mt19937::result_type> SkipList<T>::Node::flip(0,1);

template<typename T>
SkipList<T>::Node::Node(T val):value(val){
	int heightOfNode{1};
	while(flip(base))
		++heightOfNode;
	nextElement.resize(heightOfNode,pair((Node*)NULL,0));
}
template<typename T>
SkipList<T>::~SkipList(){
	Node *temp;
	while(head){
		temp=head->nextElement[0].first;
		delete head;
		head=temp;
	}
}

template<typename T>
void SkipList<T>::insert(T ele){
	Node *newNode=new Node(ele);
	stack<pair<Node*,int>> s;
	int height,newCount{1};
	head->nextElement.resize(max(head->nextElement.size(),newnode->nextElement.size()),pair((Node*)NULL,head->nextElement.back()));
	height=head->nextElement.size()-1;
	s.emplace(head,0);
	while(height>=0){
		while(s.top().first->nextElement[height].first!=NULL&&!(newNode->value>s.top().first->nextElement[height].first->value)){
			s.top().second+=s.top().first->nextElement[height].second;
			s.top().first=s.top.first->nextElement[height].first;
		}
		s.emplace(s.top().first,0);
	}
	s.pop();
	while((height=head->nextElement.size()-s.size())<newNode->nextElement.size()){
		newNode->nextElement[height]=pair(s.top().first->nextElement[height].first,s.top().first->nextElement[height].second-newCount+1);
		s.top().first->nextElement[height]=pair(newNode,newCount);
		newCount+=s.top().second;
		s.pop();
	}
	while((height=head->nextElement.size()-s.size())<head->nextElement.size()){
		++s.top().first->nextElement[height].second;
		s.pop();
	}
}
template<typename T>
pair<bool,T> SkipList<T>::lower_bound(T ele){
	Node *temp=head;
	int height=head->nextElement.size()-1;
	while(height>=0){
		while(temp->nextElement[height].first!=NULL&&temp->nextElement[height].first->value<ele){
			temp=temp->nextElement[height].first;
		}
		--height;
	}
	if(temp->nextElement[0].first==NULL)
		return pair(false,ele);
	else
		return pair(true,temp->nextElement[0].first->value);
}
template<typename T>
T SkipList<T>::upper_bound(T ele){
	Node *temp=head;
	int height=head->nextElement.size()-1;
	while(height>=0){
		while(temp->nextElement[height].first!=NULL&&!(ele<temp->nextElement[height].first->value)){
			temp=temp->nextElement[height].first;
		}
		--height;
	}
	if(temp->nextElement[0].first==NULL)
		return pair(false,ele);
	else
		return pair(true,temp->nextElement[0].first->value);
}
template<typename T>
T SkipList<T>::find(int rank){
	Node *temp=head;
	int height=head->nextElement.size()-1;
	while(height>=0){
		while(temp->nextElement[height].second<=rank){
			rank-=temp->nextElement[height].second;
			temp=temp->nextElement[height].first;
		}
		--height;
	}
	return temp->nextElement[0].first->value;
}
template<typename T>
bool SkipList<T>::erase(T ele){
	Node *toRemove;
	stack<pair<Node*,int>> s;
	int height;
	height=head->nextElement.size()-1;
	s.emplace(head,0);
	while(height>=0){
		while(s.top().first->nextElement[height].first!=NULL&&!(newNode->value>s.top().first->nextElement[height].first->value)){
			s.top().second+=s.top().first->nextElement[height].second;
			s.top().first=s.top.first->nextElement[height].first;
		}
		s.emplace(s.top().first,0);
	}
	s.pop();
	if(s.top().first->nextElement[0]==NULL||s.top().first->nextElement[0]->value<ele||ele<s.top().first->nextElement[0]->value)
		return false;
	toRemove=s.top().first->nextElement[0];
	while((height=head->nextElement.size()-s.size())<toRemove->nextElement.size()){
		s.top().first->nextElement[height]=pair(toRemove->nextElement[height],s.top().first->nextElement[height].second+toRemove->nextElement[height].second-1);
		s.pop();
	}
	while((height=head->nextElement.size()-s.size())<head->nextElement.size()){
		--s.top().first->nextElement[height].second;
		s.pop();
	}
	return true;
}
template<typename T>
int SkipList<T>::rank(T toFind){
	int ans{0},height=head->nextElement.size()-1;
	Node *temp=head;
	while(height>=0){
		if(temp->nextElement[height].first!=NULL&&temp->nextElement[height].first->value<toFind){
			ans+=temp->nextElement[height].second;
			temp=temp->nextElement[height].first;
		}
		--height;
	}
	return ans;
}
template<typename T>
SkipList<T> SkipList<T>::split(T ele){
	stack<pair<Node*,int>> s;
	int height,newCount{0};
	SkipList<T> ans(head->value);
	height=head->nextElement.size()-1;
	ans.head->nextElement.resize(nextElement.size(),pair((Node*)NULL,0))
	s.emplace(head,0);
	while(height>=0){
		while(s.top().first->nextElement[height].first!=NULL&&!(ele<s.top().first->nextElement[height].first->value)){
			s.top().second+=s.top().first->nextElement[height].second;
			s.top().first=s.top.first->nextElement[height].first;
		}
		s.emplace(s.top().first,0);
	}
	s.pop();
	while((height=head->nextElement.size()-s.size())<head->nextElement.size()){
		ans.head->nextElement[height]=pair(s.top().first->nextElement[height].first,s.top().first->nextElement[height].second-newCount);
		s.top().first->nextElement[height]=pair((Node*)NULL,newCount);
		newCount+=s.top().second;
		s.pop();
	}
	return ans;
}
