class Mover{
    constructor(ct,url,width,height){
        this.container = ct;
        this.img = new Image();
        this.container.appendChild(this.img);
        this.container.style.cssText=`
            position: absolute;
            width: ${width}px;
            height: ${height}px;
            border: 1px solid #000;
            overflow: hidden;
        `;
        this.img.src = url;
        this.img.onload = () => {
            const sx = width / this.img.width;
            const sy = height /  this.img.height;
            this.scale = sx < sy ? sx : sy;

            this.center = {
                x: -(this.img.width - this.img.width * this.scale) / 2,
                y: -(this.img.height - this.img.height * this.scale) / 2
            }
    
            this.update();
        }
        this.addEvent();
    }

    update(){
        this.img.style.transform = `
            translate(${this.center.x}px,${this.center.y}px) 
            scale(${this.scale}) 
        `;
    }

    sizeOut(){
        this.scale += 0.1;
        this.update();
    }

    sizeIn(){
        if (this.scale >= 0.1)
            this.scale -= 0.1;
        this.update();
    }

    addEvent(){
        this.container.addEventListener('mousedown',(e)=>{
            e.preventDefault();
            this.startPoint = {
                x:e.offsetX,
                y:e.offsetY
            }

        })

        this.container.addEventListener('mousemove',(e)=>{
            if(this.startPoint === undefined){
                return;
            }
            if(e.target === this.container)
            {
                this.startPoint = undefined;
                return;
            }
            this.center.x += (e.offsetX - this.startPoint.x) * this.scale;
            this.center.y += (e.offsetY - this.startPoint.y) * this.scale;
            this.update();
        })

        this.container.addEventListener('mouseup',(e)=>{
            this.startPoint = undefined;
        })
    }
}