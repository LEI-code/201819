abstract class Polygon{
	Polygon(Point[] points){
		if(!isPolygonValid())throw InvalidArgumentException("Points Provided Do Not Form A Valid Polygon");
		pts = points;
	}
	Polygon(int vertices){
		if(!isPolygonValid())throw InvalidArgumentException("Points Provided Do Not Form A Valid Polygon");
		pts = new Point[vertices];
		for (int i = 0; i < vertices; i++)pts[i] = new Point(0, 0);
	}

	private Point[] pts;

	private boolean isPolygonValid(){
		for (int i = 0; i < pts.length-1; i++)
			for (int j = i+1; j < pts.length; i++)
				if(pts[i].equals(pts[j]))
					return false;

		Line l = new Line(pts[0], pts[1]);

		int ptsOnLine = 2;
		for (int i = 2; i < pts.length && l.side(pts[i]) == 0; i++, ptsOnLine++);
		if(pts.length == ptsOnLine)return false;
		return true;
	}

	public abstract boolean isValid();
	public abstract double perimeter();
	public abstract double area();

	protected void set(char index, Point val){
		pts[index - 'a'] = val;
	}
	protected void set(int index, Point val){
		pts[index] = val;
	}

	public Point get(char index){
		return pts[index - 'a'];
	}
	public Point get(int index){
		return pts[index];
	}
}
