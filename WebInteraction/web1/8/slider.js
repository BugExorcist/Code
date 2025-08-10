class Slider{
    constructor(ct,urls){
        this.container = ct;
        this.urls = urls;
        this.innerCt = document.createElement('div');
        this.width = this.container.offsetWidth;
        this.height = this.container.offsetHeight;
        this.index = 0;
        this.container.style.cssText = `
            position:relative;
            overflow:hidden;
        `;
        this.innerCt.style.cssText = `
            width: ${urls.length * this.width}px;
            height:${this.height}px;
            padding:0;
            margin:0;
            transition: transform 1s ease;
            display:flex;
        `;
        for(let url of urls){
            const div = document.createElement('div');
            div.style.cssText = `
                width:${this.width}px;
                height:${this.height}px;
                display:flex;
                justify-content:center;
                align-items:center;
            `;
            const img = new Image();
            img.src = url;
            img.style.cssText = `
                max-width:${this.width}px;
                max-height:${this.height}px;
            `;
            div.appendChild(img);
            this.innerCt.appendChild(div);
        }

        this.container.appendChild(this.innerCt);

        this.addCircle();
        this.addButton();
        this.slideTo(this.index);
    }

    addCircle() {
        const circleCt = document.createElement('div');
        circleCt.style.cssText = `
            position:absolute;
            bottom:0px;
            height:30px;
            opacity:0.8;
            width:100%;
        `;
        circleCt.setAttribute('align','center');
        this.circles = [];
        for(let i=0;i<this.urls.length;i++){
            const c = document.createElement('div');
            c.style.cssText = `
                width:10px;
                height:10px;
                border-radius:5px;
                background-color:#888;
                display:inline-block;
                margin:0 5px;
            `;
            circleCt.appendChild(c);
            this.circles.push(c);
            c.addEventListener('click', () => {
                this.slideTo(i);
            });
        }
        this.container.appendChild(circleCt);
    }

    addButton() {
        const btn1 = document.createElement('button');
        btn1.innerHTML = '<';
        btn1.style.cssText = `
            position:absolute;
            top:50%;
            left:0;
            height:30px;
            line-height:30px;
            margin-top:-15px;
        `;
        btn1.addEventListener('click', () => {
            this.slideTo(this.index - 1 >= 0 ? this.index - 1 : this.urls.length - 1);
        });
        const btn2 = document.createElement('button');
        btn2.innerHTML = '>';
        btn2.style.cssText = `
            position:absolute;
            top:50%;
            right:0;
            height:30px;
            line-height:30px;
            margin-top:-15px;
        `;
        btn2.addEventListener('click', () => {
            this.slideTo(this.index + 1 >= this.urls.length ? 0 : this.index + 1);
        });
        this.container.appendChild(btn1);
        this.container.appendChild(btn2);
        
    }

    slideTo(num) {
        this.innerCt.style.transform = `translateX(${-num *this.width}px)`;

        if (this.index !== undefined){
            this.circles[this.index].style.backgroundColor = '#888';
        }
        this.index = num;
        this.circles[this.index].style.backgroundColor = 'red';
    }
}