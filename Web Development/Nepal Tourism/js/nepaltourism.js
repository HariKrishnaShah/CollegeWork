$(document).ready(function(){
	$(window).scroll(function(){
		if($(window).scrollTop()>95){
			$(".btn-menu").show();
		}
		else{
			$(".btn-menu").hide();
		}
	});

	$("#btn-1").click(function(){
		$("#sm-1").toggle();
		$("#btn-1").
	});
	$("#btn-2").click(function(){
		$("#sm-2").toggle();
	});
	$("#btn-3").click(function(){
		$("#sm-3").toggle();
	});
	$("#btn-4").click(function(){
		$("#sm-4").toggle();
	});
	$("#btn-5").click(function(){
		$("#sm-5").toggle();
	});
	$("#btn-6").click(function(){
		$("#sm-6").toggle();
	});
	$("#btn-7").click(function(){
		$("#sm-7").toggle();
	});
	$("#btn-8").click(function(){
		$("#sm-8").toggle();
	});
	
	
	var left1 = document.getElementById('detail-1').style.height;
	var right1 = document.getElementById('detail-2').style.height;
	var left2 = document.getElementById('detail-3').style.height;
	var right2 = document.getElementById('detail-4').style.height;

	if ((left1>right1) && (left1>left2) && (left1>right2)){
		document.getElementById('detail-2').style.height=left1;
		document.getElementById('detail-3').style.height=left1;
		document.getElementById('detail-4').style.height=left1;
	}
	else if ((left2>right1) && (left2>left1) && (left2>right2)){
		document.getElementById('detail-1').style.height=left2;
		document.getElementById('detail-2').style.height=left2;
		document.getElementById('detail-4').style.height=left2;
	}
	else if ((right1>left1) && (right1>left2) && (right1>right2)){

		document.getElementById('detail-1').style.height=right1;
		document.getElementById('detail-3').style.height=right1;
		document.getElementById('detail-4').style.height=right1;
	}
	else{
		document.getElementById('detail-1').style.height=right2;
		document.getElementById('detail-2').style.height=right2;
		document.getElementById('detail-3').style.height=right2;
	}

});
