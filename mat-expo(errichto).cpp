#define REP(i,n) for(int i = 0; i < (n); i++)
const int mod = 1e9 + 7;
int s;
struct Matrix {
	vector<vector<int>> a = vector<vector<int>>(s, vector<int>(s));
	Matrix operator *(const Matrix& other) {
		Matrix product;
		REP(i,s)REP(j,s)REP(k,s) {
			product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long k) {
	Matrix product;
	REP(i,s) product.a[i][i] = 1;
	while(k > 0) {
		if(k % 2) {
			product = product * a;
		}
		a = a * a;
		k /= 2;
	}
	return product;
}
