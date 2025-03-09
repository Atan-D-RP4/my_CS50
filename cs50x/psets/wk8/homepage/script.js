const circle1 = document.querySelector('.circle1');
const circle2 = document.querySelector('.circle2');

for (const i = 0; i < 10; i++) {
	const span1 = document.createElement('span');
	span1.style.setProperty('--i', i)
	circle1.appendChild(span1);

	const span2 = document.createElement('span');
	span2.style.setProperty('--i', i)
	circle2.appendChild(span2);

}
