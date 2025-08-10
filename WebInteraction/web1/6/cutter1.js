class Cutter{
    constructor(ct, url, width, height){
        this.container = ct;
        this.img = new Image();
        this.cover = document.createElement('div');
        this.canvas = document.createElement('canvas');
        this.container.appendChild(this.img);
        this.container.appendChild(this.cover);
        this.container.appendChild(this.canvas);
        this.img.src = url;
        this.img.onload = ()=>{
            const sx = this.img.width/width;
            const sy = this.img.height/height;
            this.scale = sx>sy?sx:sy;
            this.img.width /= this.scale;
        }
        this.cover.style.cssText = `position:absolute; width:0; height:0;background-color:#777;opacity:0.5;`;
        this.container.style.position = 'relative';
        this.addEvent();
    }

    addEvent(){
        this.container.addEventListener('mousedown',(e)=>{
            e.preventDefault();
            this.startPoint = {
                x:e.pageX,
                y:e.pageY
            }
            this.cover.style.left = this.startPoint.x + 'px';
            this.cover.style.top = this.startPoint.y + 'px';

        })
        this.container.addEventListener('mousemove',(e)=>{
            if(this.startPoint === undefined){
                return;
            }

            this.currentPoint = {
                x: e.pageX,
                y: e.pageY
            };

            // const x = e.pageX;
            // const y = e.pageY;
            // this.cover.style.width = (x - this.startPoint.x) + 'px';
            // this.cover.style.height = (y - this.startPoint.y) + 'px';
            const minX = Math.min(this.startPoint.x, this.currentPoint.x);
            const minY = Math.min(this.startPoint.y, this.currentPoint.y);
            const maxX = Math.max(this.startPoint.x, this.currentPoint.x);
            const maxY = Math.max(this.startPoint.y, this.currentPoint.y);

            this.cover.style.left = minX + 'px';
            this.cover.style.top = minY + 'px';
            this.cover.style.width = (maxX - minX) + 'px';
            this.cover.style.height = (maxY - minY) + 'px';
        })
        this.container.addEventListener('mouseup',(e)=>{
            const ctx = this.canvas.getContext('2d');
            const minX = Math.min(this.startPoint.x, this.currentPoint.x);
            const minY = Math.min(this.startPoint.y, this.currentPoint.y);
            const dw = Math.abs(this.currentPoint.x - this.startPoint.x);
            const dh = Math.abs(this.currentPoint.y - this.startPoint.y);
            // const dw = e.pageX - this.startPoint.x;
            // const dh = e.pageY - this.startPoint.y;
            this.canvas.width = dw;
            this.canvas.height = dh;
            ctx.drawImage(this.img,
                minX * this.scale,
                minY * this.scale,
                dw * this.scale,
                dh * this.scale,
                0,0,dw,dh
            );
            this.startPoint = undefined;
            this.currentPoint = undefined;
            this.cover.style.width = 0;
            this.cover.style.height = 0;
        })
    }
}