class Triangle extends Polygon{
	public Triangle(Point[] pts){super(pts);
		if(pts.length != 3)
			throw new java.lang.IllegalArgumentException("Triangle Must Have 3 Points");
		//TODO: check for colinearity of the points
	}
	public Triangle(Point a, Point b, Point c){super(new Point[3]);
		this.set('a', a);this.set('b', b);this.set('c', c);
	}

	public double perimeter(){
		return 
			this.get('a').dist(this.get('b')) + 
			this.get('b').dist(this.get('c')) + 
			this.get('c').dist(this.get('a'))
		;
	}
	public double area(){
		Point a = this.get('a');
		Point b = this.get('b');
		Point c = this.get('c');
		return Math.abs((
			a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)
		)	/
			2
		);
	}
}