//Power function LOG_POWER
ll power(ll a,ll b,ll mod=MOD){
	ll ans=1;
	for(ll i=0;(1LL<<i)<=b;++i){
		ans*=(b&(1LL<<i)?a:1LL);
		ans%=mod;
		a*=a;
		a%=mod;
	}
	return ans;
}
//Ordered sets with find by order and find order of ORDERED_SET
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//Min priority queue MIN_QUEUE
template <typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;
//Random hash base RAN_HASH
seed_seq seq{
	(uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
	(uint64_t) __builtin_ia32_rdtsc(),
	(uint64_t) (uintptr_t) make_unique<char>().get()
};
mt19937 rng(seq);
const long long int base = uniform_int_distribution<int>(0, ModularInteger::_mod-1)(rng);
