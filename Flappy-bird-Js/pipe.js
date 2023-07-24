class Pipe { 
  constructor(src) {
    this.width = canvas.width * 0.2;
    this.height = canvas.height * 0.75;
    this.gap = canvas.height * 0.20;                 // gap between upper and lower pipe images
    this.pos = {};
    this.pos.x = canvas.width + 300;          // show after some time on game start
    this.pos.y1 = getRandomNumber();            // y pos of up facing pipe
    this.pos.y2 = this.pos.y1 - this.gap - this.height;    // of down facing pipe
    this.imgUp = new Image();
    this.imgUp.src ="./assets/pipe.png";
    this.imgDown = new Image();
    this.imgDown.src = "./assets/pipedown.png";
  }
  
  update() {
    this.pos.x -= bg_speed;            // scroll to left
    
    if(this.pos.x < -this.width){    // if scrolled offscreen to left , draw right side of screen
      this.pos.y1 = getRandomNumber();
      this.pos.y2 = this.pos.y1 - this.gap - this.height;
      this.pos.x = canvas.width;              // same for all objects
    }
  }
  
  draw() {
    ctx.drawImage(this.imgUp, this.pos.x, this.pos.y1, this.width, this.height);
    ctx.drawImage(this.imgDown, this.pos.x, this.pos.y2, this.width, this.height);
  }
}