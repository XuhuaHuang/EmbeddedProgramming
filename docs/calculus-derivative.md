# Basic Derivatives

## Definition of Derivative

$$\lim_{\delta x\to\ 0} \frac{dy}{dx} = \lim_{\delta x\to\ 0} \frac{f(x0 + \delta x) - f(x0)}{\delta x} $$

$$\delta x =h $$

$$\lim_{h\to\ 0} \frac{f(x0 + h) - f(x0)}{h} $$

$$ f'(x) = \lim_{h\to\ 0} \frac{f(x + h) - f(x)}{h} $$

## Approach from Left and Right

Suggest that f(x) is derivable on open range `]a, b[`, therefore:

At left end a,
$$ f'(a) $$
approaching from the right hand side exists.

At right end b,
$$ f'(b) $$
approaching from the left hand side exists.

Thus f(x) is derivable on close range `[a, b]`.

## Practice Problems

- Solve for f'(x) given f(x):
$$ f(x) = 2x^{3} - 5x^{2} + 3x -7 $$
$$ f'(x) = (2x^{3})' - (5x^{2})' + (3x)' - (7)' $$
$$ f'(x) = 6x^{2} - 10x + 3 $$

- Solve for f'(x) given f(x):
$$ f(x) = x^{3} + 4cos(x) - sin(\frac{\pi}{2}) $$
$$ f'(x) = 3x^{2} - 4sin(x) $$

- Solve for f'(x) given f(x):
$$ f(x) = e^{x}(sinx + cosx) $$
$$ f'(x) = (e^{x})' (sinx + cosx) + (e^{x}) (sinx + cosx)' $$
$$ f'(x) = e^{x} (sinx + cosx) + e^{x} (cosx - sinx) = e^{x}(sinx + cosx + cosx - sinx) $$
$$ f'(x) = 2e^{x} cosx $$

- Solve for f'(x) given f(x):
$$ f(x) = tanx $$
$$ f(x) = \frac{sinx}{cosx} $$
$$ f'(x) = \frac{(sinx)'cosx - sinx(cosx)'}{cos^{2}x} $$
$$ f'(x) = \frac{(cosx)cosx - sinx(-sinx)}{cos^{2}x} = \frac{cos^{2}x + sin^{2}x}{cos^{2}x} $$
$$ f'(x) = \frac{1}{cos^{2}x} = (\frac{1}{secx})^{2} = sec^{2}x $$
