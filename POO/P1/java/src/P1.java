public class P1{
	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int pAmt = sc.nextInt();
		Mesh mechaQueen = new Mesh(pAmt);
		for (int i = 0; i < pAmt; i++) mechaQueen.push(new Point(sc.nextDouble(), sc.nextDouble()));

		Point[] externals = mechaQueen.externPoints();

		for (int i = 0; i < externals.length; i++) {
			System.out.print("(" + externals[i].x + ", " + externals[i].y + ") ");
		}

		System.out.println();

		/*Point a = new Point(sc.nextDouble(), sc.nextDouble());
		Point b = new Point(sc.nextDouble(), sc.nextDouble());
		Point c = new Point(sc.nextDouble(), sc.nextDouble());
		Line mid = new Line(a, b);
		System.out.println(mid.side(c));*/
	}
}