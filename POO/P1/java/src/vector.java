class Vector{
	Vector(Point a, Point b){
		this.x = b.x - a.x;
		this.y = b.y - a.y;
	}
	Vector(double x, double y){
		this.x = x; this.y = y;
	}

	boolean equals(Vector v){
		return x == v.x && y == v.y;
	}
	boolean equals_neg(Vector v){
		return (Math.abs(x) == Math.abs(v.x) && y == v.y) || (x == v.x && Math.abs(y) == Math.abs(v.y));
	}

	double mangitude(){
		return Math.sqrt(this.x*this.x + this.y*this.y);
	}
	double dotProduct(Vector v){
		return this.x * v.x + this.y * v.y;
	}
	Vector getNormalized(){
		return new Vector(x/this.mangitude(), y/this.mangitude());
	}

	public double x, y;
}