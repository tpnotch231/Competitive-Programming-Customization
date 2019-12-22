mkdir $1
cp ./generator.sh ./$1/
chmod +x ./$1/generator.sh
cd $1
touch input
touch output
echo "#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen(\"input\", \"r\", stdin);
    	freopen(\"output\", \"w\", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);

}" > $1a.cpp
gvim $1a.cpp
