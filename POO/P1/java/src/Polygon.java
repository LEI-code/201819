abstract class Polygon{
	Polygon(Point[] points){
		pts = points;
	}
	Polygon(int vertices){
		pts = new Point[vertices];
		for (int i = 0; i < vertices; i++)pts[i] = new Point(0, 0);
	}

	private Point[] pts;

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
