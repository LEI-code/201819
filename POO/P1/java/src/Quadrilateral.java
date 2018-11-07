class Quadrilateral extends Polygon{

	public enum Type{
		CONCAVE, CONVEX, PARALLELOGRAM, RECTANGLE, SQUARE
	}

	public Quadrilateral(Point[] pts){super(pts);
		if(pts.length != 4)
			throw new java.lang.IllegalArgumentException("Quadrilateral Must Have 4 Points");
	}

	public double perimeter(){
		return 
			this.get('a').dist(this.get('b')) + 
			this.get('b').dist(this.get('c')) + 
			this.get('c').dist(this.get('d')) +
			this.get('d').dist(this.get('a'))
		;
	}
	public double area(){
		//TODO: implement this
		//watch out for concave and self-crossing
		return 0;
	}

	public Type getType(){
		if(!isConcave()){
			if(isParallelogram()){
				if(isRectangle()){
					if(isSquare()){
						return Type.SQUARE;
					}else{
						return Type.RECTANGLE;
					}
				}else{
					return Type.PARALLELOGRAM;
				}
			}else{
				return Type.CONVEX;
			}
		}else{
			return Type.CONCAVE; 
		}
	}

	private boolean isConcave(){
		Point a = get('a'); Point b = get('b');
		Point c = get('c'); Point d = get('d');
		if(a == null || b == null || c == null || d == null)return false;
		Triangle abc = new Triangle(a, b, c);
		Triangle abd = new Triangle(a, b, d);
		Triangle adc = new Triangle(a, d, c);
		Triangle dbc = new Triangle(d, b, c);
		double a1 = abc.area(); double a2 = abd.area();
		double a3 = adc.area(); double a4 = dbc.area();
		return (a1 == a2+a3+a4) || (a2 == a1+a3+a4) || (a3 == a1+a2+a4) || (a4 == a1+a2+a3);
	}

	private boolean isParallelogram(){ 	//assumes is convex quad
		Point a = get('a'); Point b = get('b');	Point c = get('c'); Point d = get('d');
		return (new Vector(a, b)).equals_neg((new Vector(c, d))) && (new Vector(b, c)).equals_neg((new Vector(d, a)));
	}

	public boolean isRectangle(){		//assumes is parallelogram
		Point a = get('a'); Point b = get('b');	Point c = get('c');
		return ((new Vector(a, b)).dotProduct((new Vector(b, c)))) == 0;
	}
	public boolean isSquare(){			//assumes is rectangle
		Point a = get('a'); Point b = get('b');	Point c = get('c');
		return a.dist(b) == b.dist(c);
	}
}