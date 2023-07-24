const deadSound = new Audio("assets/sfx/hit.mp3");
let score = 0;
let birdCrossedPipe = false;

function detectCollisions(bird, pipe) {
  if (bird.pos.x + bird.width > pipe.pos.x && bird.pos.x < pipe.pos.x + pipe.width){    
    if (bird.pos.y + bird.height > pipe.pos.y1 || bird.pos.y < pipe.pos.y1 - pipe.gap){
      gameOver();
    }
  }
        // If bird successfully crosses the pipe, increase the score (execute only once)
  else if (bird.pos.x > pipe.pos.x + pipe.width && !birdCrossedPipe) {
    score++;
    if (score % 2 == 0) bg_speed += 0.4;
     birdCrossedPipe = true; // Set the flag to true to prevent score increment in subsequent frames
  }

   // Reset the flag when the pipe goes off the screen
  if (pipe.pos.x < -pipe.width + bg_speed) {
    birdCrossedPipe = false;
  }
}

function gameOver(){
  deadSound.play();
  loop = false;        // collision detected stop game's animation loop
}

function drawScore() {
  // Set the font and text color.
  ctx.font = "25px Arial";
  ctx.fillStyle = "black";

  // Draw the score text.
  ctx.fillText(score, 10, 20);
}
