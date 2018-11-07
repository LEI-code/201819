class Point{
	Point(double x, double y){
		this.x = x; this.y = y;
	}
	Point(Point p){
		this.x = p.x; this.y = p.y;
	}

	public double x;
	public double y;
	
	static double Distance(double x1, double y1, double x2, double y2){
		return Math.sqrt((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2));
	}
	double dist(Point p){
		return Distance(this.x, this.y, p.x, p.y);
	}
	double dist(double x, double y){
		return Distance(this.x, this.y, x, y);
	}
}