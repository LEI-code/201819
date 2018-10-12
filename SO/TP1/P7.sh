imgList=""
tindex=0

mkdir -p mins
for fil in $(ls *.jpg | sed -e 's/\..*$//');do
	convert $fil.jpg -resize 600x400^ -gravity Center -extent 600x400 mins/${fil}_min.jpg

	imgList[$tindex]="$fil"
	tindex=$(($tindex+1))
done

tindex=0
imageElements=""
for fil in ${imgList[@]}; do
	echo "
		<!DOCTYPE html>
		<html>
			<head>
				<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">
				<style>
					a {text-decoration: none; display: inline-block; padding: 8px 16px;}
					a:hover {background-color: #ddd; color: black;}
					.previous {background-color: #f1f1f1; color: black;}
					.next {background-color: #4CAF50; color: white;}
				</style>
			</head>
			<body>
				<center>
					<h2>$1: $fil</h2>
					<a href=\"${imgList[$((($tindex-1) % (${#imgList[@]})))]}.html\" class=\"previous\">
							&laquo; Previous
					</a>
					<a href=\"../index.html\" class=\"next\">Back</a>
					<a href=\"${imgList[$((($tindex+1) % (${#imgList[@]})))]}.html\" class=\"previous\">
							Next &raquo;
					</a><br><br><img src=\"../${fil}.jpg\">
				</center> 
			</body>
		</html> " > mins/$fil.html

	imageElements+="
		<div class=\"responsive\">
			<div class=\"gallery\">
				<a href=\"mins/${fil}.html\">
					<img src=\"mins/${fil}_min.jpg\" alt=\"Cinque Terre\" width=\"600\" height=\"400\">
				</a>
				<div class=\"desc\">
					${fil}
				</div>
			</div>
		</div>"

	tindex=$(($tindex+1))
done

echo "
	<!DOCTYPE html>
	<html>
		<head>
			<style>
				div.gallery {border: 1px solid #ccc;}
				div.gallery:hover {border: 1px solid #777;}
				div.gallery img {width: 100%; height: auto;}
				div.desc {padding: 15px; text-align: center;}
				* {box-sizing: border-box;}
				.responsive {padding: 0 6px; float: left; width: 24.99999%;}
				@media only screen and (max-width: 700px) {    
					.responsive {width: 49.99999%; margin: 6px 0;}
				}
				@media only screen and (max-width: 500px) {
					.responsive {width: 100%;}
				}
				.clearfix:after {content: \"\"; display: table; clear: both;}
			</style>
		</head>
		<body>
			<h2>
				$1
			</h2>

			
			$imageElements


			<div class=\"clearfix\">
			</div>
			<div style=\"padding:6px;\">
			</div>
		</body>
	</html>" > index.html

read -p "Would you like to open the generated (\"$1\") website? [Y/N] " resp
case $resp in 
	"Y")xdg-open index.html	;;
	"y")xdg-open index.html	;;
	"N")echo ended			;;
	"n")echo ended			;;
esac