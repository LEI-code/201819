public class P1{
	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int pAmt = sc.nextInt();
		Mesh mechaQueen = new Mesh(pAmt);
		for (int i = 0; i < pAmt; i++) mechaQueen.push(new Point(sc.nextDouble(), sc.nextDouble()));

		Point[] externals = mechaQueen.externPoints();

		if(externals.length == 3){
			Triangle tri = new Triangle(externals);
			System.out.println("triangle " + tri.perimeter());
		}else if(externals.length == 4){
			Quadrilateral quad = new Quadrilateral(externals);
			String yeet = "";
			switch (quad.getType()){
				case CONCAVE:
					yeet = "CONCAVE?! THIS WAS SUPPOSED TO BE IMPOSSIBRU";
					break;
				case CONVEX:
					yeet = "quadrilateral";
					break;
				case PARALLELOGRAM:
					yeet = "parallelogram";
					break;
				case RECTANGLE:
					yeet = "rectangle";
					break;
				case SQUARE:
					yeet = "square";
					break;
			}
			System.out.println(yeet + " " + quad.perimeter());
		}else{
			System.out.println("niggersfuckingjewsgodisdeadhitlerdidnothingwrong");
		}





		/*for (int i = 0; i < externals.length; i++) {
			System.out.print("(" + externals[i].x + ", " + externals[i].y + ") ");
		}System.out.println();*/

		/*Point a = new Point(sc.nextDouble(), sc.nextDouble());
		Point b = new Point(sc.nextDouble(), sc.nextDouble());
		Point c = new Point(sc.nextDouble(), sc.nextDouble());
		Line mid = new Line(a, b);
		System.out.println(mid.side(c));*/
	}
}