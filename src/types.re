type snippet_code = {
re: string,
js: string,
test: string
};

type snippet = {
code: snippet_code,
title: string,
tags: list(string),
description: string,
notes: list(string),
id: string
};
