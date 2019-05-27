/*
 * Copyright (c) 2019, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

package jdk.jfr.api.consumer.filestream;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.IdentityHashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;

import jdk.jfr.Event;
import jdk.jfr.Recording;
import jdk.jfr.consumer.EventStream;
import jdk.jfr.consumer.RecordedEvent;

/**
 * @test
 * @summary Test EventStream::setReuse(...)
 * @key jfr
 * @requires vm.hasJFR
 * @library /test/lib
 * @run main/othervm jdk.jfr.api.consumer.filestream.TestReuse
 */
public class TestReuse {

    static class ReuseEvent extends Event {
    }

    public static void main(String... args) throws Exception {
        Path p = makeRecording();

        testSetReuseTrue(p);
        testSetReuseFalse(p);
    }

    private static void testSetReuseFalse(Path p) throws Exception {
        AtomicBoolean fail = new AtomicBoolean(false);
        Map<RecordedEvent, RecordedEvent> identity = new IdentityHashMap<>();
        try (EventStream es = EventStream.openFile(p)) {
            es.setReuse(false);
            es.onEvent(e -> {
                if (identity.containsKey(e)) {
                    fail.set(true);
                    throw new Error("Unexpected reuse!");
                }
                identity.put(e,e);
            });
            es.start();
        }
        if (fail.get()) {
            throw new Exception("Unexpected resued");
        }
    }

    private static void testSetReuseTrue(Path p) throws Exception {
        AtomicBoolean fail = new AtomicBoolean(false);
        try (EventStream es = EventStream.openFile(p)) {
            es.setReuse(true);
            RecordedEvent[] events = new RecordedEvent[1];
            es.onEvent(e -> {
                if (events[0] == null) {
                    events[0] = e;
                } else {
                    if (e != events[0]) {
                        fail.set(true);
                        throw new Error("No reuse");
                    }
                }
            });
            es.start();
        }
        if (fail.get()) {
            throw new Exception("No reuse");
        }
    }

    private static Path makeRecording() throws IOException {
        try (Recording r = new Recording()) {
            r.start();
            for (int i = 0; i < 2_000_000; i++) {
                ReuseEvent e = new ReuseEvent();
                e.commit();
            }
            r.stop();
            Path p = Files.createTempFile("recording", ".jfr");
            r.dump(p);
            return p;
        }
    }
}
