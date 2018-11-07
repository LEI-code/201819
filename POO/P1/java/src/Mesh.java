class Mesh{
	public Mesh(int pointAmount){
		this.points = new Point[pointAmount];
		this.finalized = false;
		this.currentPoint = 0;
	}

	private boolean finalized;
	private Point[] points;
	private int currentPoint;

	public void push(Point p){
		if(this.currentPoint == this.points.length)
			throw new java.lang.IllegalStateException("Mesh Was Full");
		this.points[this.currentPoint++] = p;
	}

	public void pop(){
		if(this.currentPoint == 0)
			throw new java.lang.IllegalStateException("Mesh Was Empty");
		this.points[--this.currentPoint] = null;
	}

	public Point[] externPoints(){
		if(this.currentPoint != this.points.length)
			throw new java.lang.IllegalStateException("Mesh Was Not Full");
		return QuickHull();		
	}

	private Point[] QuickHull(){
		if(this.currentPoint < 3)
			throw new java.lang.IllegalStateException("Mesh Had Less Than 3 Points");
		Point leftest = points[0]; int leftestIndex = 0;
		Point rghtest = points[0]; int rghtestIndex = 0;
		for (int i = 1; i < this.currentPoint; i++) {
			if(points[i].x < leftest.x){leftest = points[i]; leftestIndex = i;}
			if(points[i].x > rghtest.x){rghtest = points[i]; rghtestIndex = i;}
		}

		Line midForLowerHalf = new Line(leftest, rghtest);
		Line midForHgherHalf = new Line(rghtest, leftest);
		java.util.List<Point> pointz = new java.util.ArrayList<Point>(java.util.Arrays.asList(points));
		pointz.remove(leftestIndex);
		pointz.remove(leftestIndex<rghtestIndex?rghtestIndex-1:rghtestIndex);

		java.util.List<Point> result = new java.util.ArrayList<Point>();
		result.add(leftest);
		result.addAll(QuickHullRecurse(midForLowerHalf, pointz));
		result.add(rghtest);
		result.addAll(QuickHullRecurse(midForHgherHalf, pointz));

		return result.toArray(new Point[result.size()]);
	}

	private java.util.List<Point> QuickHullRecurse(Line l, java.util.List<Point> allPoints){
		java.util.List<Point> pointsToTheRight = new java.util.ArrayList<Point>();

		for (int i = 0; i < allPoints.size(); i++) 		//for every point
			if(l.side(allPoints.get(i)) > 0) 			//if it's on the right
				pointsToTheRight.add(allPoints.get(i));	//add it to pointsToTheRight

		//if no points to the right, our job is done, return empty list
		if(pointsToTheRight.size() == 0)return pointsToTheRight;

		//if there are points, get furthest
		Point furthest = pointsToTheRight.get(0);
		int furthestIndex = 0;
		double furthestDist = 0;

		for (int i = 0; i < pointsToTheRight.size(); i++){		//for every point to the right
			double distToLine = l.dist(pointsToTheRight.get(i));//get distance of current point to the OG line
			if(distToLine > furthestDist){						//if it's greater than the last registered
				furthestIndex = i;								//swap it
				furthestDist = distToLine;						//swap it
				furthest = pointsToTheRight.get(i);				//swap it
			}
		}														//at this point we have most distant point to the right

		// so now we make 2 lines:
		Line first = new Line(l.a, furthest);	//one from our line's first point to the furthest found
		Line secnd = new Line(furthest, l.b);	//anothe from furthest found to our line's second point

		pointsToTheRight.remove(furthestIndex);	//and we remove the furthest (common to both lines) from the list

		java.util.List<Point> result = new java.util.ArrayList<Point>();	//create list for result

		result.addAll(QuickHullRecurse(first, pointsToTheRight)); //this is gonna give us the points in the subdivisions of first
		result.add(furthest);									  //here we add back furthest so it's present(?) also makes it ordered
		result.addAll(QuickHullRecurse(secnd, pointsToTheRight)); //this is gonna give us the points in the subdivisions of secnd
		return result;											  //now we return this line's every subdivision to the right
	}
}