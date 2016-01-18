$(document).ready(function() {
	var scrollChk = function() {
		if (window.pageYOffset > 380) {
			$("nav").removeClass("aboveVideo");
		} else {
			$("nav").addClass("aboveVideo");
		}
	};
	$(window).scroll(scrollChk);
	scrollChk();
});
