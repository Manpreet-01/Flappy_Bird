class Bird {
  constructor(x = 55, y = 0) {
    this.pos = { x, y };
    this.height = 24 * 1.4;        // size scaling factor
    this.width = 34 * 1.4;
    this.vel = 0;
    this.frameCounter = 0;
    this.birdUp = new Image();
    this.birdUp.src = "./assets/birdup.png";
    this.birdDown = new Image();
    this.birdDown.src = "./assets/birddown.png";
    this.flapWings = true;                // boolean for switch between birdup and birddown images
    this.gravity = 0.23;
    this.jumpForce = 5.5;
    this.jumpSound = new Audio("assets/sfx/flap.mp3");
  }
  draw() {
    this.update();
    ctx.drawImage(this.img, this.pos.x, this.pos.y, this.width, this.height);
  }
  update() {
    ++this.frameCounter;
    if (this.frameCounter % 8 == 0) this.flapWings = !this.flapWings;    // -> %flapWinsSpeed here

    if (this.flapWings) {              // based on boolean switch images of bird's wings flap up or down
      this.img = this.birdUp;
    } else {
      this.img = this.birdDown;
    }

    this.vel += this.gravity;

    this.pos.y += this.vel;

    if (this.pos.y + this.height > ground_y) {    // if collide with ground, no downward motion, just still
      this.pos.y = ground_y - this.height;
      gameOver();
    }

    if (this.pos.y < 0) {    // collide with sky, no upward motion, just still
      this.vel = 0;
      this.pos.y = 0;
    }
  }

  jump() {
    this.jumpSound.play();
    this.vel = -this.jumpForce;    // on each jump upward velocity & upward distance is constant
  }
}