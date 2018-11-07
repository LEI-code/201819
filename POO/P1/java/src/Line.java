class Line{
	Line(double x1, double y1, double x2, double y2){
		if(x1 == x2 && y1 == y2)
			throw new java.lang.IllegalArgumentException("Points Cannot Be The Same");
		this.a = new Point(x1, y1);
		this.b = new Point(x2, y2);
	}

	Line(Point a, Point b){
		this(a.x, a.y, b.x, b.y);
	}

	public Point a, b;

	public double dist(Point c){
		return Math.abs(
			(b.y - a.y)*c.x - (b.x - a.x)*c.y + b.x*a.y - b.y*a.x
		)/Math.sqrt(
			(b.y - a.y)*(b.y - a.y) + (b.x - a.x)*(b.x - a.x)
		);
	}

	// < 0 is on left side
	// > 0 is on right side
	// = 0 is on the line
	public double side(Point c){
		return (c.x - a.x)*(b.y - a.y) - (c.y - a.y)*(b.x - a.x);
	}
}