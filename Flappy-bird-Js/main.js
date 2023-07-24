const canvas = document.getElementById("myCanvas");
const ctx = canvas.getContext("2d");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

const ground_width = canvas.width;
const ground_height = canvas.height * 0.20;
const ground_y = canvas.height * 0.85;
let ground1_x = 0;
let ground2_x = ground_width;

let bg_speed = 2;
let loop = true;

const bird = new Bird();
const pipe = new Pipe();

function animate() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  if (ground1_x + ground_width <= 0) {
    ground1_x = ground2_x + ground_width;
  }

  if (ground2_x + ground_width <= 0) {
    ground2_x = ground1_x + ground_width;
  }

  ground1_x -= bg_speed;
  ground2_x -= bg_speed;

  pipe.update();
  detectCollisions(bird, pipe);

  ctx.drawImage(bg, 0, 0, canvas.width, canvas.height);

  bird.draw();
  pipe.draw();

  ctx.drawImage(ground, ground1_x, ground_y, ground_width, ground_height);
  ctx.drawImage(ground, ground2_x, ground_y, ground_width, ground_height);

  drawScore();
  
  if (loop) {
    requestAnimationFrame(animate);
  }
}


canvas.addEventListener("click", () => {
  if(loop) bird.jump();
  else location.reload();
});


function getRandomNumber() {
  const minY = canvas.height * 0.30;
  const maxY = canvas.height * 0.75;
  return Math.floor(Math.random() * (maxY - minY + 1)) + minY;
  // return minY;
  // return maxY;
}


window.addEventListener('load', animate);