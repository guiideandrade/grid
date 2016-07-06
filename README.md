# Grid v2.1.x

Home page: [guiideandrade/grid](http://guiideandrade.com/project/grid)

See section 3 and code-you-should-use.css for more specific codes.

# 1 - License

Copyright (C) 2016 Guilherme de Andrade Arantes.

This program is **free software**: copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved.

This work is licensed under the *Creative Commons BY SA 4.0 License*

Visit [license](http://creativecommons.org/licenses/by-sa/4.0/) or send a letter to *Creative Commons, PO Box 1866, Mountain View, CA 94042, USA* to view a copy of this licence.

This program is distributed in the hope that it will be useful, but *without any warranty*; without even the implied warranty of *merchantability or fitness for a particular purpose*.

# 2 - Why "Grid v2.x.x"?

I am proud of Grid-v1's size: the `gr` flavor was just 1.630 B! Then, I don't want to mess with this and in order to add some features in the grid system, I created this new branch on git-hub. 

In this release, there is not a default ready-to-use file, instead we have a few `grid` files. These files can be combined, to keep integration easier with other codes, but that is not necessary. In development, these files are kept separeted.

**I love to write free software (it isn't a software, it's just a CSS file, anyways...), you should check out my git-hub page at [git-hub](http://github.com/guiideandrade) or contact me at my [page](http://guiideandrade.com)**

# 3 - Files

```
├── README.md
├── code-you-should-use.css
├── grid-basic.css
├── grid.css
├── grid-default-basic.css
├── grid-default-initial.css
├── grid-default-offset.css
├── grid.min.css
├── main.cpp
├── breakpoints
│   └── *.css
└── recommended
    └── *.css
```

Some of these files is not needed in prodution, but you should checkout at least *code-you-should-use.css* and this *README.md* file.

## 3.1 - ./README.md

This file. It's the best way I found to communicate about the project. It contains some directives, some links, etc.

I tried to keep this file updated, but the comments in code are usually more accurated than README.md.

## 3.2 - ./code-you-shoud-use.css

This file includes some CSS properties. These codes are recommended, you should consider this lines (it's very small).

## 3.3 - ./grid-basic.css

Definition of `.row`, `.col` and `.float`.

## 3.4 - ./grid.css

Compiled version of *grid-basic.css, grid-default-initial.css, grid-default-offset.css and all css files in folder ./recommended/*. Some files were edited and contain only grids 1-8.

## 3.5 - ./grid-default-basic.css

This file contains 12 grids (1-12) for all viewports.

## 3.6 - ./grid-default-initial.css

This file implements default sizes. For example:

```html
<div class="gr4">...</div>
```

All `.col` elements inside this div will be 25% by default.

## 3.7 - ./grid-default-offset.css

Offsets, or 'empty cols'; You may edit it to be margin-right, if rtl is needed.

## 3.8 - ./grid.min.css

Minified version of grid.css (see 3.4).

## 3.9 - ./main.cpp

I used this c++ file to create base css files. I choose to leave it in the project, because it may be useful for me and others.

## 3.10 - ./breakpoints folder

This folder contains files modified to use specific breakpoint. But all viewports have from 1 to 12-column grid.

## 3.11 - ./recommended folder

This folder contains recommended versions of this project, modified to use breakpoint. Grid availability for device:

  * small devices: 1-2
  * medium devices: 1-4
  * large devices: 1-6
  * extra large devices: 1-8
